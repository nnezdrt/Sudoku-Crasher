#include <stdio.h>
#include <string.h>
#include <queue>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)<0?(-(x)):(x))
#define maxn 205
#define maxm 25001
#define INF 99999999
struct node
{
	int a,b,w,f,next;
}t[maxm],nod[maxn];
int head[maxn],all,num,ans;
int n,m;
void inline add(int a,int b,int c)
{
	t[all].a=a;
	t[all].b=b;
	t[all].w=c;
	t[all].f=1;
	t[all].next=head[a];
	head[a]=all;
	t[++all].a=b;
	t[all].b=a;
	t[all].w=-c;
	t[all].f=0;
	t[all].next=head[b];
	head[b]=all;
	++all;
}
void spfa(int from,int to)
{
	while (1)
	{
		std::queue<int> q;
		int dis[maxn],last[maxn];
		bool used[maxn]={0};
		used[from]=1;
		q.push(from);
		for (int i=1;i<=maxn;++i)
		{
			dis[i]=INF;
			last[i]=-1;
		}
		dis[from]=0;
		while (q.size())
		{
			int now=q.front();
			q.pop();
			for (int i=head[now];i+1;i=t[i].next)
			{
				int v=t[i].b;
				if (t[i].f && t[i].w+dis[now]<dis[v])
				{
					dis[v]=dis[now]+t[i].w;
					last[v]=i;
					if (!used[v])
					{
						used[v]=1;
						q.push(v);
					}
				}
			}
			used[now]=0;
		}
		if (last[to]==-1)
			break;
		ans+=dis[to];
		for (int i=last[to];i!=-1;i=last[t[i].a])
		{
			t[i].f--;
			t[i^1].f++;
		}
	}
}
int main()
{
	while (~scanf("%d%d",&n,&m),n)
	{
		getchar();
		ans=all=0;
		int ch,house=0,man=0;
		memset(head,-1,sizeof(head));
		for (int i=1;i<=n;++i)
		{
			for (int j=1;j<=m;++j)
			{
				ch=getchar();
				if (ch=='m')
				{
					++man;
					nod[man].a=i;
					nod[man].b=j;
				}
				else if (ch=='H')
				{
					++house;
					nod[house+100].a=i;
					nod[house+100].b=j;
				}
			}
			getchar();
		}
		for (int i=1;i<=man;++i)
		{
			add(man+101,i,0);
			add(i+100,man+102,0);
			for (int j=1;j<=house;++j)
			{
				int c=abs(nod[i].a-nod[j+100].a)+abs(nod[i].b-nod[j+100].b);
				add(i,j+100,c);
			}
		}
		spfa(man+101,man+102);
		printf("%d\n",ans);
	}
	return 0;
}
