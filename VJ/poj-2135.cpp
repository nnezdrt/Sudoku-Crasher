#include <stdio.h>
#include <string.h>
#include <queue>
#define INF 999999999
#define maxn 1001
#define maxm 40001
using namespace std;
struct node
{
	int from,to,f,c,next;
}t[maxm];
int n,m,ans,head[maxn],all=-1;
void dijkstra()
{
	int tick=2;
	while (tick--)
	{
		bool used[maxn]={0};
		int dis[maxn],last[maxn]={-1,-1},flow=INF;
		queue<int>q;
		for (int i=1;i<=n;++i)
			dis[i]=INF;
		dis[1]=0;
		q.push(1);
		while (q.size())
		{
			int now=q.front();
			q.pop();
			used[now]=0;
			for (int i=head[now];i!=-1;i=t[i].next)
			{
				int to=t[i].to;
				if (t[i].f && dis[now]+t[i].c<dis[to])
				{
					dis[to]=dis[now]+t[i].c;
					flow=min(flow,t[i].f);
					last[to]=i;
					if (!used[to])
					{
						used[to]=1;
						q.push(to);
					}
				}
			}
		}
		if (dis[n]==INF)
			return;
		ans+=dis[n];
		for (int i=last[n];i!=-1;i=last[t[i].from])
		{
			t[i].f-=flow;
			t[i^1].f+=flow;
		}
	}
}
void inline add(int a,int b,int c)
{
	t[++all].from=a;
	t[all].to=b;
	t[all].c=c;
	t[all].f=1;
	t[all].next=head[a];
	head[a]=all;
	t[++all].from=b;
	t[all].to=a;
	t[all].c=-c;
	t[all].f=0;
	t[all].next=head[b];
	head[b]=all;
}
int main()
{
	memset(head,-1,sizeof(head));
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;++i)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
	}
	dijkstra();
	printf("%d\n",ans);
	return 0;
}
