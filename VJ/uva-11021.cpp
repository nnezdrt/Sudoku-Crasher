#include <stdio.h>
#include <math.h>
double t,n,m,k;
int main()
{
	scanf("%lf",&t);
	for (int i=1;i<=t;++i)
	{
		scanf("%lf%lf%lf",&n,&k,&m);
		double p[1001],f[1001]={0};
		for (int j=0;j<n;++j)
			scanf("%lf",&p[j]);
		for (int j=1;j<=m;++j)
			for (int l=0;l<n;++l)
				f[j]+=pow(f[j-1],l)*p[l];
		printf("Case #%d: %.7lf\n",i,pow(f[(int)m],k));
	}
	return 0;
}
