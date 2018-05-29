#include <algorithm>
#include <stdio.h>
using namespace std;
#define maxn 45
#define maxm 1001
int n,m,x[maxn],y[maxn];
int main()
{
	int tt,first=1;
	scanf("%d",&tt);
	for (int cas=1;cas<=tt;++cas)
	{
		if (first)
			first=0;
		else
			printf("\n");
		printf("Matrix %d\n",cas);
		scanf("%d%d",&n,&m);
		int t=n+m+1,f[maxn][maxn]={0};
		for (int i=1;i<=n;++i)
			scanf("%d",&x[i]);
		for (int i=1;i<=m;++i)
			scanf("%d",&y[i]);
		for (int i=n;i>=1;--i)
		{
			x[i]-=x[i-1]+m;
			f[0][i]=x[i];
		}
		for (int i=m;i>=1;--i)
		{
			y[i]-=y[i-1]+n;
			f[n+i][t]=y[i];
		}
		for (int i=1;i<=n;++i)
			for (int j=1;j<=m;++j)
				f[i][n+j]=19;
		while (1)
		{
			int r[maxn]={99999999},pre[maxn]={0},list[maxn]={0},top=1,ss=1;
			while (top<=ss)
			{
				int now=list[top++];
				for (int i=0;i<=t;++i)
					if (!r[i] && f[now][i])
					{
						r[i]=min(r[now],f[now][i]);
						list[++ss]=i;
						pre[i]=now;
					}
			}
			if (!r[t])
				break;
			for (int i=t;i;i=pre[i])
			{
				int from=pre[i];
				f[from][i]-=r[t];
				f[i][from]+=r[t];
			}
		}
		for (int i=1;i<=n;++i)
		{
			for (int j=1;j<=m;++j)
				printf("%d ",20-f[i][n+j]);
			printf("\n");
		}
	}
	return 0;
}
