#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 101;
int t,n,v,ans,f[maxn];
int w,val,c;
void update(){
	int temp;
	for (int i=1;i<c;i+=i){
		c -= i;
		temp = i*w;
		for (int j=v;j>=temp;--j){
			if (f[j] < f[j-temp] + val*i){
				f[j] = f[j-temp] + val*i;
				ans = max(ans, f[j]);
			}
		}
	}
	temp = c*w;
	for (int i=v;i>=temp;--i){
		if (f[i] < f[i-temp] + c*val){
			f[i] = f[i-temp] + c*val;
			ans = max(ans, f[i]);
		}
	}
}
int main(){
	scanf("%d",&t);
	while (t--){
		ans = 0;
		memset(f,0,sizeof(f));
		scanf("%d%d",&v,&n);
		for (int i=1;i<=n;++i){
			scanf("%d%d%d",&w,&val,&c);
			update();
		}
		printf("%d\n",ans);
	}
	return 0;
}
