#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define maxn 655
#define maxm 4001
#define INF 0x7fffffff
int head[maxn],v[maxm],f[maxm],cap[maxm],nex[maxm],all;
int e,n,t,need,dis[maxn],cur[maxn],list[maxn],w[30],d[30];
bool win[30];
inline void add(int a,int b,int c)
{
	cap[all]=c;
	v[all]=b;nex[all]=head[a];head[a]=all++;
	cap[all]=0;
	v[all]=a;nex[all]=head[b];head[b]=all++;
}
bool bfs()
{
	memset(dis,0,sizeof(dis));
	dis[0]=1;
	int top=1,ss=1;
	while (top<=ss)
	{
		int now=list[top++];
		for (int i=head[now];i+1;i=nex[i])
		{
			int to=v[i];
			if (!dis[to] && cap[i]>f[i])
			{
				dis[to]=dis[now]+1;
				list[++ss]=to;
			}
		}
	}
	return dis[t];
}
int dfs(int now,int a)
{
	if (now==t || a==0)
		return a;
	int ff,ret=0;
	for (int &i=cur[now];i+1;i=nex[i])
	{
		int to=v[i];
		if (dis[to]==dis[now]+1 && cap[i]>f[i])
		{
			ff=dfs(to,min(cap[i]-f[i],a));
			if (!ff)
				continue;
			ret+=ff;
			a-=ff;
			f[i]+=ff;
			f[i^1]-=ff;
			if (!a)
				return ret;
		}
	}
	return ret;
}
void maxFlow(int now)
{
	int i,flow=0;
	memset(f,0,sizeof(f));
	for (i=head[t];i+1;i=nex[i])
	{
		if (v[i]==now+e)
		{
			cap[i^1]=INF;
			continue;
		}
		cap[i^1]=0;
	}
	while (bfs())
	{
		for (i=0;i<t;++i)
			cur[i]=head[i];
		int temp=dfs(0,INF);
		flow+=temp;
		if (!temp)
			break;
	}
	int s=flow+w[now];
	for (i=head[t];i+1;i=nex[i])
	{
		int to=v[i];
		cap[i^1]=s-w[to-e];
		if (cap[i^1]<0)
			return;
	}
	while (bfs())
	{
		for (i=0;i<t;++i)
			cur[i]=head[i];
		int temp=dfs(0,INF);
		flow+=temp;
		if (!temp)
			break;
	}
	if (flow!=need)
		return;
	for (i=head[t];i+1;i=nex[i])
		if (f[i^1]==s-w[v[i]-e])
			win[v[i]-e]=1;
}
int main()
{
	int tt,temp,tick;
	scanf("%d",&tt);
	while (tt--)
	{
		memset(head,-1,sizeof(head));
		memset(win,0,sizeof(win));
		scanf("%d",&n);
		all=0;
		e=n*n;
		tick=0;
		need=0;
		t=n*n+n+1;
		for (int i=1;i<=n;++i)
			scanf("%d%d",&w[i],&d[i]);
		for (int i=1;i<=n;++i)
		{
			add(e+i,t,0);
			for (int j=1;j<=n;++j)
			{
				++tick;
				scanf("%d",&temp);
				if (i<j)
				{
					add(0,tick,temp);
					add(tick,e+i,INF);
					add(tick,e+j,INF);
					need+=temp;
				}
			}
		}
		for (int i=1;i<=n;++i)
			if (!win[i])
				maxFlow(i);
		bool flag=1;
		for (int i=1;i<=n;++i)
		{
			if (win[i])
			{
				if (flag)
				{
					flag=0;
					printf("%d",i);
				}
				else
					printf(" %d",i);
			}
		}
		printf("\n");
	}
	return 0;
}
