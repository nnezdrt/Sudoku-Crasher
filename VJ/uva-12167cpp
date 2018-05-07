#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define abs(x) ((x)<0?(-(x)):(x))
#define maxn 20001
#define maxm 50001
int head[maxn],v[maxm],nex[maxm],all;
int g[maxn],vis[maxn],low[maxn],stack[maxn],s;
int n,m,T;
bool used[maxn];
inline void add(int a,int b)
{
	v[++all]=b;
	nex[all]=head[a];
	head[a]=all;
}
bool dfs(int now)
{
	used[now]=vis[now]=low[now]=++s;
	stack[++stack[0]]=now;
	for (int i=head[now];i;i=nex[i])
	{
		int to=v[i];
		if (!vis[to])
		{
			dfs(to);
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
			g[temp]=g[0];
			used[temp]=0;
		}while (temp!=now);
	}
}
int main()
{
	int a,b;
	scanf("%d",&T);
	while (T--)
	{
		memset(head,0,sizeof(head));
		memset(low,0,sizeof(low));
		memset(vis,0,sizeof(vis));
		all=s=g[0]=stack[0]=0;
		scanf("%d%d",&n,&m);
		while (m--)
		{
			scanf("%d%d",&a,&b);
			add(a,b);
		}
		for (int i=1;i<=n;++i)
			if (!vis[i])
				dfs(i);
		if (g[0]==1)
		{
			printf("0\n");
			continue;
		}
		int in[maxn]={0},out[maxn]={0};
		for (int i=1;i<=n;++i)
		{
			for (int j=head[i];j;j=nex[j])
			{
				b=v[j];
				if (g[i]!=g[b])
				{
					++out[g[i]];
					++in[g[b]];
				}
			}
		}
		for (int i=1;i<=g[0];++i)
		{
			if (!in[i])
				++in[0];
			if (!out[i])
				++out[0];
		}
		printf("%d\n",max(in[0],out[0]));
	}
	return 0;
}
