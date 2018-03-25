#include <stdio.h>
#include <string.h>
#define min(a,b) ((a)<(b)?(a):(b))
#define maxn 231
#define INF 50000
bool used[maxn];
int map[maxn][maxn],b[maxn][maxn],match[maxn][maxn],g[maxn];
int n,m,k,c;
bool dfs(int now)
{
	for (int i=1;i<=k;++i)
		if (b[i][now] && !used[i])
		{
			used[i]=1;
			if (g[i]<m)
			{
				match[i][++g[i]]=now;
				return 1;
			}
			for (int j=1;j<=m;++j)
				if (dfs(match[i][j]))
				{
					match[i][j]=now;
					return 1;
				}
		}
	return 0;
}
int main()
{
	scanf("%d%d%d",&k,&c,&m);
	n=k+c;
	for (int i=1;i<=n;++i)
		for (int j=1;j<=n;++j)
		{
			scanf("%d",&map[i][j]);
			if (!map[i][j])
				map[i][j]=INF;
		}
	for (int t=1;t<=n;++t)
		for (int i=1;i<=n;++i)
			for (int j=1;j<=n;++j)
				map[i][j]=min(map[i][j],map[i][t]+map[t][j]);
	int l=1,r=INF,mid,flag;
	while (l<r)
	{
		flag=0;
		mid=(l+r)/2;
		for (int i=1;i<=n;++i)
		{
			g[i]=0;
			for (int j=1;j<=n;++j)
				match[i][j]=b[i][j]=0;
		}
		for (int i=1;i<=k;++i)
			for (int j=k+1;j<=n;++j)
				if (map[i][j]<=mid)
					b[i][j]=1;
		for (int i=1;i<=c;++i)
		{
			memset(used,0,sizeof(used));
			if (!dfs(i+k))
			{
				l=mid+1;
				flag=1;
				break;
			}
		}
		if (!flag)
			r=mid;
	}
	printf("%d\n",l);
	return 0;
}
