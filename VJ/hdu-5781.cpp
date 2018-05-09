#include <algorithm>
#include <stdio.h>
using namespace std;
#define maxn 2001
#define maxm 12
int n,m;
double f[maxn][maxm];
int main()
{
	for (int i=1;i<=2000;++i)
		for (int j=0;j<=11;++j)
			f[i][j]=999999;
	for (int i=1;i<=2000;++i)
		for (int j=1;j<=11;++j)
			for (int k=1;k<=i;++k)
				f[i][j]=min(f[i][j],1+(k/(i+1.0))*f[k-1][j-1]+((i+1.0-k)/(i+1.0))*f[i-k][j]);
	while (~scanf("%d%d",&n,&m))
		printf("%.6lf\n",f[n][min(11,m)]);
	return 0;
}
