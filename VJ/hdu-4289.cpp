#include <stdio.h>
#include <string.h>
#define min(a,b) ((a)<(b)?(a):(b))
#define maxn 503
#define maxm 90001
#define INF 0x7fffffff
int head[maxn],u[maxm],v[maxm],f[maxm],next[maxm],all;
int n,m,from,to,ans;
inline void add(int a,int b,int c)
{
	u[all]=a;
	v[all]=b;
	f[all]=c;
	next[all]=head[a];
	head[a]=all++;
	u[all]=b;
	v[all]=a;
	f[all]=0;
	next[all]=head[b];
	head[b]=all++;
}
int main()
{
	while (~scanf("%d%d",&n,&m))
	{
		all=ans=0;
		memset(head,-1,sizeof(head));
		int x,a,b;
		scanf("%d%d",&from,&to);
		to+=n;
		for (int i=1;i<=n;++i)
		{
			scanf("%d",&x);
			add(i,i+n,x);
		}
		for (int i=1;i<=m;++i)
		{
			scanf("%d%d",&a,&b);
			add(a+n,b,INF);
			add(b+n,a,INF);
		}
		while (1)
		{
			int last[maxn],list[maxn]={1,from},flow[maxn],top=1,now;
			for (int i=0;i<maxn;++i)
			{
				last[i]=-1;
				flow[i]=INF;
			}
			while (top<=list[0])
			{
				now=list[top++];
				for (int i=head[now];i+1;i=next[i])
				{
					int go=v[i];
					if (f[i] && last[go]==-1)
					{
						flow[go]=min(flow[now],f[i]);
						last[go]=i;
						list[++list[0]]=go;
					}
				}
			}
			if (flow[to]==INF)
				break;
			ans+=flow[to];
			for (int i=last[to];v[i]!=from;i=last[u[i]])
			{
				f[i]-=flow[to];
				f[i^1]+=flow[to];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
