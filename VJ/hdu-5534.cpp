#include <cstdio>
int t,n,f[2018],dp[2018];
int main(){
	scanf("%d",&t);
	while (t--){
		int k;
		scanf("%d%d",&n,&k);
		for (int i=1;i<n-1;++i){
			dp[i] = -0x7fffffff;
			scanf("%d",&f[i]);
			f[i]-=k;
		}
		for (int i=1;i<=n-2;++i){
			for (int j=0;j<=n-2-i;++j){
				if (dp[j+i] < dp[j] + f[i]){
					dp[i+j] = dp[j] + f[i];
				}
			}
		}
		printf("%d\n",k*n+dp[n-2]);
	}
	return 0;
}
