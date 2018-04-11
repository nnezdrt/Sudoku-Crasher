#include <stdio.h>
int main()
{
	int t,n,f[1001]={0,1,3},c[1001][1001]={1};
	for (int i=1;i<=1000;++i){
		c[i][0]=f[i]=1;
		for (int j=1;j<=i;++j){
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%10056;
			f[i]=(f[i]+c[i][j]*f[i-j])%10056;
		}
	}
	scanf("%d",&t);
	for (int i=1;i<=t;++i){
		scanf("%d",&n);
		printf("Case %d: %d\n",i,f[n]);
	}
	return 0;
}
