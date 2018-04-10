#include <stdio.h>
long long n,m;
int main()
{
	while (scanf("%lld%lld",&n,&m),n)
	{
		if (n>m)
			n^=m^=n^=m;
		long long ans=n*m*(m+n-2)+(m-n+1)*2*n*(n-1),t=0;
		for (long long i=n-1;i>=2;--i)
			t+=i*(i-1);
		printf("%lld\n",ans+t*4);
	}
	return 0;
}
