#include <stdio.h>
#define maxn 1000001
long long s[maxn],n;
int main()
{
	s[4]=1;
	for (long long i=5;i<maxn;i+=2)
	{
		s[i]=s[i-1]+(i-3)*(i-1)/4;
		s[i+1]=s[i]+(i-1)*(i-1)/4;
	}
	while (scanf("%lld",&n),(n>=3))
		printf("%lld\n",s[n]);
	return 0;
}
