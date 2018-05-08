#include <stdio.h>
#include <algorithm>
using namespace std;
#define maxn 1001
#define maxm 50001
int head[maxn],u[maxm],v[maxm],nex[maxm],all;
int vis[maxn],low[maxn],stack[maxn],g[maxn],tick[maxn],dp[maxn],s;
bool map[maxn][maxn],used[maxn];
inline void add(int a,int b)
{
	v[++all]=b;
	u[all]=a;
	nex[all]=head[a];
	head[a]=all;
}
void tarjan(int now)
{
	used[now]=vis[now]=low[now]=++s;
	stack[++stack[0]]=now;
	for (int i=head[now];i;i=nex[i])
	{
		int to=v[i];
		if (!vis[to])
		{
			tarjan(to);
			low[now]=min(low[now],low[to]);
		}
		else if (used[to])
			low[now]=min(low[now],vis[to]);
	}
	if (low[now]==vis[now])
	{
		int temp;
		++g[0];
		do
		{
			temp=stack[stack[0]--];
			used[temp]=0;
			g[temp]=g[0];
		}while (temp!=now);
	}
}
int dfs(int now)
{
	dp[now]=tick[now];
	for (int i=head[now];i;i=nex[i])
	{
		int to=v[i];
		if (dp[to])
			dp[now]=max(dp[now],tick[now]+dp[to]);
		else
			dp[now]=max(dp[now],tick[now]+dfs(to));
	}
	return dp[now];
}
int main()
{
	int n,m,t,a,b;
	scanf("%d",&t);
	while (t--)
	{
		all=s=g[0]=0;
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n;++i)
		{
			head[i]=tick[i]=low[i]=vis[i]=dp[i]=0;
			for (int j=1;j<=n;++j)
				map[i][j]=0;
		}
		while (m--)
		{
			scanf("%d%d",&a,&b);
			add(a,b);
		}
		for (int i=1;i<=n;++i)
			if (!vis[i])
				tarjan(i);
		for (int i=1;i<=n;++i)
			head[i]=0;
		int tempall=all,ans=0;
		all=0;
		for (int i=1;i<=tempall;++i)
		{
			a=g[u[i]];b=g[v[i]];
			if (a!=b && map[a][b]==0)
			{
				map[a][b]=1;
				add(a,b);
			}
		}
		for (int i=1;i<=n;++i)
			++tick[g[i]];
		for (int i=1;i<=g[0];++i)
		{
			if (!dp[i])
				dfs(i);
			ans=max(ans,dp[i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}
