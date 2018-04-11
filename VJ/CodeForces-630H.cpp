#include <stdio.h>
int main()
{
	long long c[101][6]={1},ans=0;
	int n;
	for (int i=1;i<=100;++i)
	{
		c[i][0]=1;
		for (int j=1;j<=5;++j)
			c[i][j]=c[i-1][j-1]+c[i-1][j];
	}
	scanf("%d",&n);
	ans=c[n][5]*n*(n-1)*(n-2)*(n-3)*(n-4);
	printf("%lld\n",ans);
	return 0;
}
