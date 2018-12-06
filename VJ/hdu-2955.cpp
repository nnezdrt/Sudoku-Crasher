#include <cstdio>
#include <cstring>
#define maxn 101
int t,n;
double pro;
int m[maxn];
double p[maxn], dp[maxn*maxn];
int main(){
	scanf("%d",&t);
	while (t--){
		int sum = 0;
		scanf("%lf%d",&pro,&n);
		for (int i=1;i<=n;++i){
			scanf("%d%lf",&m[i],&p[i]);
			sum += m[i];
		}
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		for (int i=1;i<=n;++i){
			for (int j=sum;j>=m[i];--j){
				if (dp[j] < dp[j-m[i]]*(1-p[i])){
					dp[j] = dp[j-m[i]] * (1-p[i]);
				}
			}
		}
		for (int i=sum;i>=0;--i){
			if (1 - dp[i] <= pro){
				printf("%d\n",i);
				break;
			}
		}
	}
	return 0;
}
