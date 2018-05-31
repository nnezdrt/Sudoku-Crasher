#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define maxn 120
#define maxm 40001
#define INF 2060000000
struct node
{
	int u,v,nex;
	long long cap,f;
	bool operator <(const node& x)const
	{return (u==x.u?v<x.v:u<x.u);}
}t[maxm],ans[maxm];
int n,m,all,head[maxn],dis[maxn],cur[maxn];
long long k;
inline void add(int a,int b,int c)
{
	t[all].u=a;t[all].v=b;t[all].cap=c;t[all].f=0;t[all].nex=head[a];head[a]=all++;
	t[all].u=b;t[all].v=a;t[all].cap=0;t[all].f=0;t[all].nex=head[b];head[b]=all++;
}
bool bfs()
{
	memset(dis,0,sizeof(dis));
	int list[maxn]={0,1},ss=1,top=1,now;
	dis[1]=1;
	while (top<=ss)
	{
		now=list[top++];
		for (int i=head[now];i!=-1;i=t[i].nex)
		{
			int to=t[i].v;
			if ((!dis[to]) && t[i].cap>t[i].f)
			{
				dis[to]=dis[now]+1;
				list[++ss]=to;
			}
		}
	}
	return dis[n];
}
long long dfs(int now,long long flow)
{
	if (now==n || flow==0)
		return flow;
	long long f,ret=0;
	for (int& i=cur[now];i!=-1;i=t[i].nex)
	{
		int to=t[i].v;
		if (dis[to]>dis[now] && (f=dfs(to,min(flow,t[i].cap-t[i].f)))>0)
		{
			ret+=f;
			flow-=f;
			t[i].f+=f;
			t[i^1].f-=f;
			if (flow==0)
				return ret;
		}
	}
	return ret;
}
void deal()
{
	long long flow=0;
	while (bfs())
	{
		for (int i=1;i<=n;++i)
			cur[i]=head[i];
		long long tem=dfs(1,INF);
		flow+=tem;
		if (flow>=k || (!tem))
			break;
	}
	if (flow>=k)
	{
		printf("possible\n");
		return;
	}
	int list[maxm]={0},sum=0,s=0;
	bfs();
	for (int i=0;i<all;++i)
		if (dis[t[i].u] && !dis[t[i].v] && t[i].cap)
			list[++s]=i;
	for (int i=0;i<all;++i)
		t[i].cap-=t[i].f;
	for (int ii=1;ii<=s;++ii)
	{
		int i=list[ii];
		long long tempflow=flow,temp;
		for (int j=0;j<all;++j)
			t[j].f=0;
		temp=t[i].cap;
		t[i].cap=k;
		while (bfs())
		{
			for (int j=1;j<=n;++j)
				cur[j]=head[j];
			long long tem=dfs(1,INF);
			tempflow+=tem;
			if (tempflow>=k || (!tem))
			break;
		}
		t[i].cap=temp;
		if (tempflow>=k)
			ans[++sum]=t[i];
	}
	if (!sum)
		printf("not possible\n");
	else
	{
		sort(ans+1,ans+sum+1);
		printf("possible option:(%d,%d)",ans[1].u,ans[1].v);
		for (int i=2;i<=sum;++i)
			if (ans[i].u!=ans[i-1].u || ans[i].v!=ans[i-1].v)
				printf(",(%d,%d)",ans[i].u,ans[i].v);
		printf("\n");
	}
}
int main()
{
	int cas=0;
	while (scanf("%d%d%lld",&n,&m,&k),n)
	{
		printf("Case %d: ",++cas);
		all=0;
		int a,b,c;
		memset(head,-1,sizeof(head));
		while (m--)
		{
			scanf("%d%d%d",&a,&b,&c);
			add(a,b,c);
		}
		deal();
	}
	return 0;
}
