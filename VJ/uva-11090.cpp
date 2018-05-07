#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define maxn 51
#define maxm 2501
#define INF 0x7fffffff
int head[maxn],nex[maxm],v[maxm],all;
double w[maxm];
bool vis[maxn];
int n,m,T;
inline void add(int a,int b,double c)
{
	v[++all]=b;
	w[all]=c;
	nex[all]=head[a];
	head[a]=all;
}
int spfa(int from)
{
	int tick[maxn]={0},list[maxm]={1,from},top=1;
	bool used[maxn]={0};
	double dis[maxm];
	for (int i=1;i<=n;++i)
		dis[i]=INF;
	dis[from]=0.0;
	vis[from]=1;
	while (top<=list[0])
	{
		int now=list[top++];
		used[now]=0;
		for (int i=head[now];i;i=nex[i])
		{
			int to=v[i];
			double ww=w[i];
			vis[to]=1;
			if (dis[to]>dis[now]+ww)
			{
				dis[to]=dis[now]+ww;
				if (!used[to])
				{
					used[to]=1;
					list[++list[0]]=to;
					if (++tick[to]>=n)
						return 0;
				}
			}
		}
	}
	return 1;
}
int deal(double ww)
{
	int i;
	memset(vis,0,sizeof(vis));
	for (i=1;i<=all;++i)
		w[i]-=ww;
	int ok=0;
	for (i=1;i<=n;++i)
		if (!vis[i])
			ok=max(ok,1-spfa(i));
	for (i=1;i<=all;++i)
		w[i]+=ww;
	return ok;
}
int main()
{
	int a,b;
	double c,k;
	scanf("%d",&T);
	for (int tt=1;tt<=T;++tt)
	{
		k=0;
		all=0;
		memset(head,0,sizeof(head));
		printf("Case #%d: ",tt);
		scanf("%d%d",&n,&m);
		while (m--)
		{
			scanf("%d%d%lf",&a,&b,&c);
			add(a,b,c);
			k=max(k,c);
		}
		if (!deal(k+1))
			printf("No cycle found.\n");
		else
		{
			double l=1,r=k,mid;
			for (int i=1;i<=100;++i)
			{
				mid=(l+r)/2;
				if (!deal(mid))
					l=mid;
				else
					r=mid;
			}
			printf("%.2lf\n",l);
		}
	}
	return 0;
}
