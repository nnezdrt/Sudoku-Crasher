#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 100001;
int n,v,ans,f[maxn];
int c,w;
void update(){
	int temp;
	for (int i=1;i<c;i+=i){
		c -= i;
		temp = i*w;
		for (int j=v;j>=temp;--j){
			if (f[j] < f[j-temp] + temp){
				f[j] = f[j-temp] + temp;
				ans = max(ans, f[j]);
			}
		}
	}
	temp = c*w;
	for (int i=v;i>=temp;--i){
		if (f[i] < f[i-temp] + temp){
			f[i] = f[i-temp] + temp;
			ans = max(ans, f[i]);
		}
	}
}
int main(){
	while (~scanf("%d%d",&v,&n)){
		ans = 0;
		memset(f,0,sizeof(f));
		for (int i=1;i<=n;++i){
			scanf("%d%d",&c,&w);
			update();
		}
		printf("%d\n",ans);
	}
	return 0;
}
