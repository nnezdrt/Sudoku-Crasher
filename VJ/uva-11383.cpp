#include <algorithm>
#include <stdio.h>
using namespace std;
#define maxn 501
#define INF 0x7fffffff
int lx[maxn],ly[maxn],match[maxn],slack[maxn],map[maxn][maxn],n,m;
bool usedx[maxn],usedy[maxn];
int dfs(int now)
{
	usedx[now]=1;
	for (int i=1;i<=n;++i)
	{	
		if (usedy[i])
			continue;
		int temp=lx[now]+ly[i]-map[now][i];
		if (temp)
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
	while (~scanf("%d",&n))
	{
		for (int i=1;i<=n;++i)
		{
			lx[i]=ly[i]=match[i]=0;
			for (int j=1;j<=n;++j)
			{
				scanf("%d",&map[i][j]);
				lx[i]=max(lx[i],map[i][j]);
			}
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
				int d=INF;
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
		long long ans=lx[1]+ly[1];
		printf("%d",lx[1]);
		for (int i=2;i<=n;++i)
		{
			printf(" %d",lx[i]);
			ans+=lx[i];
		}
		printf("\n%d",ly[1]);
		for (int i=2;i<=n;++i)
		{
			printf(" %d",ly[i]);
			ans+=ly[i];
		}
		printf("\n%lld\n",ans);
	}
	return 0;
}
