#include <stdio.h>
double np[100001],ans;
int n,k,l,r;
int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;++i)
	{
		scanf("%d%d",&l,&r);
		long long temp=l/k*k;
		double tick=0;
		if (temp<l)
			temp+=k;
		if (temp<=r)
			tick=(r-temp)/k+1;
		np[i]=(r-l+1-tick)/(r-l+1);
	}
	ans=2000*(1-np[1]*np[n]);
	for (int i=1;i<n;++i)
		ans+=2000*(1-np[i]*np[i+1]);
	printf("%.7lf\n",ans);
	return 0;
}
