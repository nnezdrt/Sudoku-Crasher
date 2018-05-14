#include <algorithm>
#include <stdio.h>
#include <cmath>
using namespace std;
#define maxn 101
#define INF (double)0x3f3f3f3f
double lx[maxn],ly[maxn],map[maxn][maxn],slack[maxn],x[2][maxn],y[2][maxn];
int n,m,match[maxn];
bool usedx[maxn],usedy[maxn];
int dfs(int now)
{
	usedx[now]=1;
	for (int i=1;i<=n;++i)
	{
		if (usedy[i])
			continue;
		double temp=lx[now]+ly[i]-map[now][i];
		if (temp>=0.0000001)
			slack[i]=min(slack[i],temp);
		else
		{
			usedy[i]=1;
			if (!match[i] || dfs(match[i]))
			{
				match[i]=now;
				return 1;
			}
		}
	}
	return 0;
}
int main()
{
	bool first=0;
	while (~scanf("%d",&n))
	{
		if (first)
			printf("\n");
		else
			first=1;
		for (int j=1;j<=n;++j)
			scanf("%lf%lf",&x[0][j],&y[0][j]);
		for (int j=1;j<=n;++j)
		{
			match[j]=lx[j]=ly[j]=0.0;
			scanf("%lf%lf",&x[1][j],&y[1][j]);
		}
		for (int i=1;i<=n;++i)
			for (int j=1;j<=n;++j)
			{
				double xx=x[0][j]-x[1][i],yy=y[0][j]-y[1][i];
				map[i][j]=INF-sqrt(xx*xx+yy*yy);
				lx[i]=max(lx[i],map[i][j]);
			}
		for (int i=1;i<=n;++i)
		{
			for (int j=1;j<=n;++j)
				slack[j]=INF;
			while (1)
			{
				for (int j=1;j<=n;++j)
					usedx[j]=usedy[j]=0;
				if (dfs(i))
					break;
				double d=INF;
				for (int j=1;j<=n;++j)
					if (!usedy[j])
						d=min(d,slack[j]);
				for (int j=1;j<=n;++j)
				{
					if (usedx[j])
						lx[j]-=d;
					if (usedy[j])
						ly[j]+=d;
					else
						slack[j]-=d;
				}
			}
		}
		for (int j=1;j<=n;++j)
			printf("%d\n",match[j]);
	}
	return 0;
}
