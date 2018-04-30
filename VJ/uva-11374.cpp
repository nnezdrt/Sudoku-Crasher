#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <queue>
using namespace std;
#define maxn 1001
#define maxm 6001
int head[maxn],v[maxm],w[maxm],nex[maxm],all;
int n,m,k,from,to,dis[maxn],pre[maxn];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
inline void add(int a,int b,int c)
{
	v[++all]=b;
	w[all]=c;
	nex[all]=head[a];
	head[a]=all;
}
void out(int x)
{
	if (x==pre[x])
	{
		printf("%d",x>n?x-n:x);
		return;
	}
	if (x>n && pre[x]<n)
		k=pre[x];
	out(pre[x]);
	printf(" %d",x>n?x-n:x);
}
void dij()
{
	bool used[maxn]={0};
	for (int i=1;i<=n+n;++i)
	{
		dis[i]=0x7fffffff;
		pre[i]=i;
	}
	dis[from]=0;
	q.push(make_pair(0,from));
	while (!q.empty())
	{
		int now=q.top().second;
		q.pop();
		if (used[now])
			continue;
		used[now]=1;
		for (int i=head[now];i;i=nex[i])
		{
			int go=v[i];
			if (!used[go] && dis[go]>dis[now]+w[i])
			{
				pre[go]=now;
				dis[go]=dis[now]+w[i];
				q.push(make_pair(dis[go],go));
			}
		}
	}
}
int main()
{
	int tick=0,a,b,c;
	while (~scanf("%d%d%d",&n,&from,&to))
	{
		if (tick++)
			printf("\n");
		all=0;
		memset(head,0,sizeof(head));
		scanf("%d",&m);
		while (m--)
		{
			scanf("%d%d%d",&a,&b,&c);
			add(a,b,c);
			add(b,a,c);
			add(a+n,b+n,c);
			add(b+n,a+n,c);
		}
		scanf("%d",&k);
		while (k--)
		{
			scanf("%d%d%d",&a,&b,&c);
			add(a,b+n,c);
			add(b,a+n,c);
		}
		dij();
		if (dis[to]>dis[to+n])
			to+=n;
		out(to);
		if (k+1)
			printf("\n%d\n%d\n",k,dis[to]);
		else
			printf("\nTicket Not Used\n%d\n",dis[to]);
	}
	return 0;
}
