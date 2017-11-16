//full of tricks
#include <cstdio>
int f[2][351],n,i,j;
#define max(a,b) ((a>b)?(a):(b))
int main()
{
	scanf("%d",&n);
	for (i=1;i<=n;++i)
		for (j=1;j<=i;++j)
		{
			scanf("%d",&f[!(i&1)][j]);
			f[!(i&1)][j]+=max(f[i&1][j],f[i&1][j-1]);
		}
	for (i=1;i<=n;++i) f[0][0]=max(f[0][0],f[!(n&1)][i]);
	printf("%d\n",f[0][0]);
	return 0;
}
