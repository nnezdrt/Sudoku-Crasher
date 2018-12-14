#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 10001, maxm = 1000001;
int n,a[maxn];
int used[maxm];
int main(){
	int t=0;
	while (scanf("%d",&n),n){
		if (t)
			printf("\n");
		++t;
		int k = 0;
		memset(used, 0, sizeof(used));
		for (int i=1;i<=n;++i){
			scanf("%d",&a[i]);
			++used[a[i]];
			k = max(k, used[a[i]]);
		}
		sort(a+1,a+n+1);
		printf("%d\n",k);
		for (int i=1;i<=k;++i){
			printf("%d",a[i]);
			for (int j=i+k;j<=n;j+=k){
				printf(" %d",a[j]);
			}
			printf("\n");
		}
	}
	return 0;
}
