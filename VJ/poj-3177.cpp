#include <stdio.h>
#define min(a,b) ((a)<(b)?(a):(b))
#define maxn 5011
#define maxm 20021
bool used[maxn];
int head[maxn],v[maxm],next[maxm];
int n,m,all,ans,low[maxn],vis[maxn],stack[maxn],g[maxn],degree[maxn];
void dfs(int now,int fa)
{
	int to,k=1;
	low[now]=vis[now]=++all;
	stack[++stack[0]]=now;
	used[now]=1;
	for (int i=head[now];i;i=next[i])
	{
		to=v[i];
		if (fa==to && k)
		{
			--k;
			continue;
		}
		if (!vis[to])
		{
			dfs(to,now);
			low[now]=min(low[now],low[to]);
		}
		else if (used[to])
			low[now]=min(low[now],vis[to]);
	}
	if (low[now]==vis[now])
	{
		++g[0];
		do
		{
			to=stack[stack[0]--];
			g[to]=g[0];
			used[to]=0;
		}while (to!=now);
	}
}
inline void add(int a,int b,int num)
{
	v[num]=b;
	next[num]=head[a];
	head[a]=num;
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y,i);
		add(y,x,i+m);
	}
	for (int i=1;i<=n;++i)
		if (!vis[i])
			dfs(i,0);
	for (int i=1;i<=n;++i)
		for (int j=head[i];j;j=next[j])
			if (g[v[j]]!=g[i])
				++degree[g[i]];
	for (int i=1;i<=n;++i)
		if (degree[i]==1)
			++ans;
	printf("%d\n",(ans+1)/2);
	return 0;
}
