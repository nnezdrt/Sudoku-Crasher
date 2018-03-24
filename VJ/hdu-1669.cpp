#include <stdio.h>
#include <string.h>
#define maxn 1001
#define maxm 500001
bool used[maxn];
int head[maxn],next[maxm],v[maxm],match[maxn][maxn],g[maxn],limit,all,n,m;
inline void add(int a,int b)
{
	v[++all]=b;
	next[all]=head[a];
	head[a]=all;
}
bool dfs(int now)
{
	for (int i=head[now];i;i=next[i])
	{
		int to=v[i];
		if (!used[to])
		{
			used[to]=1;
			if (g[to]<limit)
			{
				match[to][++g[to]]=now;
				return 1;
			}
			else
			{
				for (int j=1;j<=g[to];++j)
				{
					if (dfs(match[to][j]))
					{
						match[to][j]=now;
						return 1;
					}
				}
			}
		}
	}
	return 0;
}
int main()
{
	while (scanf("%d%d",&n,&m),n)
	{
		getchar();
		memset(head,0,sizeof(head));
		for (int i=1;i<=n;++i)
		{
			char name[18];
			scanf("%s",name);
			getchar();
			int ch,num=0;
			while ((ch=getchar())!='\n')
			{
				if (ch>='0' && ch<='9')
				{
					num=num*10+ch-'0';
				}
				else
				{
					add(i,num+1);
					num=0;
				}
			}
			add(i,num+1);
		}
		int l=1,r=n,flag,ans=0;
		while (l<r)
		{
			flag=0;
			limit=(l+r)/2;
			memset(g,0,sizeof(g));
			memset(match,0,sizeof(match));
			for (int i=1;i<=n;++i)
			{
				memset(used,0,sizeof(used));
				if (!dfs(i))
				{
					l=limit+1;
					flag=1;
					break;
				}
			}
			if (!flag)
				r=limit;
		}
		printf("%d\n",l);
	}
	return 0;
}
