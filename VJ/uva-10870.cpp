#include <stdio.h>
#define maxn 16
long long n,m,d,a[maxn][maxn],f[maxn];
void mul()
{
	n-=d;
	long long tempa[maxn][maxn]={0},tempc[maxn][maxn]={0},i,j,k;
	for (i=1;i<=d;++i)
		tempa[i][i]=1;
	while (n)
	{
		if (n&1)
		{
			for (k=1;k<=d;++k)
				for (i=1;i<=d;++i)
					for (j=1;j<=d;++j)
						tempc[i][k]=(tempc[i][k]+tempa[i][j]*a[j][k]%m)%m;
			for (i=1;i<=d;++i)
				for (j=1;j<=d;++j)
				{
					tempa[i][j]=tempc[i][j];
					tempc[i][j]=0;
				}
		}
		n/=2;
		for (k=1;k<=d;++k)
			for (i=1;i<=d;++i)
				for (j=1;j<=d;++j)
					tempc[i][k]=(tempc[i][k]+a[i][j]*a[j][k]%m)%m;
		for (i=1;i<=d;++i)
			for (j=1;j<=d;++j)
			{
				a[i][j]=tempc[i][j]%m;
				tempc[i][j]=0;
			}
	}
	for (i=1;i<=d;++i)
		for (j=1;j<=d;++j)
			a[i][j]=tempa[i][j];
}
int main()
{
	while (scanf("%lld%lld%lld",&d,&n,&m),d)
	{
		for (int i=1;i<d;++i)
		{
			for (int j=1;j<=d;++j)
				a[i][j]=0;
			a[i][i+1]=1;
		}
		for (int i=d;i>=1;--i)
			scanf("%lld",&a[d][i]);
		for (int i=1;i<=d;++i)
			scanf("%lld",&f[i]);
		if (d>=n)
		{
			printf("%lld\n",f[n]%m);
			continue;
		}
		mul();
		long long ans=0;
		for (int i=1;i<=d;++i)
			ans+=f[i]*a[d][i];
		printf("%lld\n",ans%m);
	}
	return 0;
}
