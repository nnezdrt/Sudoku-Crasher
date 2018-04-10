#include <stdio.h>
#define mod 1000007
int t,n,m,k;
int c[401][401];
void preDeal()
{
	c[1][1]=c[1][0]=1;
	for (int i=2;i<=400;++i)
	{
		c[i][0]=1;
		for (int j=1;j<=i;++j)
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
	}
}
int main()
{
	preDeal();
	scanf("%lld",&t);
	for (int i=1;i<=t;++i)
	{
		scanf("%d%d%d",&n,&m,&k);
		if (n*m<k || k<2)
		{
			printf("Case %d: 0\n",i);
			continue;
		}
		int ans=c[(n-1)*m][k]*2-c[(n-2)*m][k]+c[n*(m-1)][k]*2-c[n*(m-2)][k];
		ans=ans-c[(n-1)*(m-1)][k]*4;
		ans+=2*(c[(n-1)*(m-2)][k]+c[(n-2)*(m-1)][k])-c[(n-2)*(m-2)][k];
		printf("Case %d: %d\n",i,(((c[n*m][k]-ans)%mod)+mod)%mod);
	}
	return 0;
}
