#include <stdio.h>
int n,a[101],i;
long long ans=1;
int main()
{
	scanf("%d",&n);
	for (i=1;i<=n;++i)
		scanf("%d",&a[i]);
	int tick=0;
	i=1;
	while (a[i]==0 && i<=n)
		++i;
	if (i==n+1)
		ans=0;
	for (++i;i<=n;++i)
	{
		if (a[i]==0)
			++tick;
		else
		{
			ans*=tick+1;
			tick=0;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
