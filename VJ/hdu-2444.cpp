#include <stdio.h>
#include <string.h>
#define maxn 201
#define maxm 40001
int n,m,k,head[maxn],v[maxm],next[maxm],match[maxn];
bool used[maxn];
inline void add(int a,int b,int num)
{
	v[num]=b;
	next[num]=head[a];
	head[a]=num;
}
bool bfs()
{
	int color[maxn]={0};
	for (int i=1;i<=n;++i)
	{
		if (color[i])
			continue;
		color[i]=1;
		int list[maxn]={1,i},top=1,now;
		while (top<=list[0])
		{
			now=list[top++];
			for (int i=head[now];i;i=next[i])
			{
				int to=v[i];
				if (!color[to])
				{
					color[to]=-color[now];
					list[++list[0]]=to;
				}
				else if (color[to]==color[now])
					return 0;
			}
		}
	}
	return 1;
}
bool dfs(int now)
{
	for (int i=head[now];i;i=next[i])
	{
		int to=v[i];
		if (!used[to])
		{
			used[to]=1;
			if (!match[to] || dfs(match[to]))
			{
				match[to]=now;
				return 1;
			}
		}
	}
	return 0;
}
int main()
{
	while (~scanf("%d%d",&n,&m))
	{
		k=0;
		memset(match,0,sizeof(match));
		memset(head,0,sizeof(head));
		for (int i=1;i<=m;++i)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			add(x,y,i);
			add(y,x,i+m);
		}
		if (!bfs())
		{
			printf("No\n");
			continue;
		}
		for (int i=1;i<=n;++i)
		{
			memset(used,0,sizeof(used));
			if (dfs(i))
				++k;
		}
		printf("%d\n",k/2);
	}
	return 0;
}
