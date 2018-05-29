#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <queue>
using namespace std;
#define maxn 2001
#define maxm 50001
#define INF 0x3f3f3f3f
int head[maxn],u[maxm],v[maxm],f[maxm],w[maxm],nex[maxm],n,m,all;
inline void add(int a,int b,int c)
{
	u[all]=a;v[all]=b;w[all]=c;f[all]=1;nex[all]=head[a];head[a]=all++;
	u[all]=b;v[all]=a;w[all]=-c;f[all]=0;nex[all]=head[b];head[b]=all++;
}
int deal()
{
	int tick=2,ret=0;
	while (tick--)
	{
		int dis[maxn]={0},pre[maxn]={-1,-1};
		bool used[maxn]={0};
		queue<int>list;
		for (int i=2;i<=n+n;++i)
			dis[i]=INF;
		list.push(1);
		used[1]=1;
		while (!list.empty())
		{
			int now=list.front();list.pop();
			used[now]=0;
			for (int i=head[now];i+1;i=nex[i])
			{
				int to=v[i];
				if (dis[to]>dis[now]+w[i] && f[i])
				{
					pre[to]=i;
					if (!used[to])
					{
						used[to]=1;
						list.push(to);
					}
					dis[to]=dis[now]+w[i];
				}
			}
		}
		if (dis[n]==INF)
			break;
		ret+=dis[n];
		for (int i=pre[n];i+1;i=pre[u[i]])
		{
			--f[i];
			++f[i|1];
		}
	}
	return ret;
}
int main()
{
	int a,b,c;
	while (~scanf("%d%d",&n,&m))
	{
		memset(head,-1,sizeof(head));
		all=0;
		while (m--)
		{
			scanf("%d%d%d",&a,&b,&c);
			if (a!=1)
				a+=n;
			add(a,b,c);
		}
		for (int i=2;i<n;++i)
			add(i,i+n,0);
		printf("%d\n",deal());
	}
	return 0;
}
