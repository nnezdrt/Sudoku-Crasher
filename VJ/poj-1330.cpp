#include <stdio.h>
#include <string.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define memset(a,b) memset(a,b,sizeof(a))
#define maxn 10001
#define maxm 10001
int head[maxn],v[maxm],next[maxm],all;
int t,n,deep[maxn],fa[maxn][21];
inline void add(int a,int b)
{
	v[++all]=b;
	next[all]=head[a];
	head[a]=all;
}
void dfs(int now)
{
	for (int i=1;i<=20;++i)
	{
		fa[now][i]=fa[fa[now][i-1]][i-1];
		if (!fa[now][i])
			break;
	}
	for (int i=head[now];i;i=next[i])
	{
		int to=v[i];
		fa[to][0]=now;
		deep[to]=deep[now]+1;
		dfs(to);
	}
}
int lca(int a,int b)
{
	if (deep[a]<deep[b])
		a^=b^=a^=b;
	for (int i=20;i>=0;--i)
	{
		if (deep[fa[a][i]]>=deep[b])
			a=fa[a][i];
	}
	if (a==b)
		return a;
	for (int i=20;i>=0;--i)
		if (fa[a][i]-fa[b][i])
		{
			a=fa[a][i];
			b=fa[b][i];
		}
	return fa[a][0];
}
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		all=0;
		memset(head,0);
		memset(deep,0);
		memset(fa,0);
		int x,y,in[maxn]={0};
		scanf("%d",&n);
		for (int i=1;i<n;++i)
		{
			scanf("%d%d",&x,&y);
			add(x,y);
			++in[y];
		}
		for (int i=1;i<=n;++i)
			if (!in[i])
			{
				dfs(i);
				break;
			}
		scanf("%d%d",&x,&y);
		if (!in[x])
			printf("%d\n",x);
		else if (!in[y])
			printf("%d\n",y);
		else
			printf("%d\n",lca(x,y));
	}
	return 0;
}
