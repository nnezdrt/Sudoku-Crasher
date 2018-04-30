#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <math.h>
using namespace std;
#define maxn 1001
#define maxm 1000001
double x[maxn],y[maxn],w[maxn*2];
int n,m,p[maxn],fa[maxn],head[maxn],v[maxn*2],nex[maxn*2],all;
struct node
{
	double w;
	int a,b;
	bool operator <(const node& x)const
	{return w<x.w;}
}t[maxm];
int getfa(int x)
{return x==fa[x]?x:fa[x]=getfa(fa[x]);}
inline void add(int a,int b,double c)
{
	v[++all]=b;
	w[all]=c;
	nex[all]=head[a];
	head[a]=all;
}
void dfs(int now,int f,double *dis)
{
	for (int i=head[now];i;i=nex[i])
	{
		int to=v[i];
		if (to==f)
			continue;
		dis[to]=max(dis[now],w[i]);
		dfs(to,now,dis);
	}
}
double mst()
{
	int tick=0;
	double sum=0,ret=0;
	for (int i=1;i<=m;++i)
	{
		int a=getfa(t[i].a),b=getfa(t[i].b);
		if (a!=b)
		{
			add(t[i].a,t[i].b,t[i].w);
			add(t[i].b,t[i].a,t[i].w);
			sum+=t[i].w;
			fa[a]=b;
			if (++tick==n-1)
				break;
		}
	}
	for (int i=1;i<=n;++i)
	{
		double dis[maxn]={0};
		dfs(i,0,dis);
		for (int j=i+1;j<=n;++j)
			ret=max(ret,(p[i]+p[j])/(sum-dis[j]));
	}
	return ret;
}
int main()
{
	int tick;
	scanf("%d",&tick);
	while (tick--)
	{
		m=all=0;
		scanf("%d",&n);
		for (int i=1;i<=n;++i)
		{
			fa[i]=i;
			head[i]=0;
			scanf("%lf%lf%d",x+i,y+i,p+i);
		}
		for (int i=1;i<=n;++i)
		{
			for (int j=i+1;j<=n;++j)
			{
				double xx=x[i]-x[j],yy=y[i]-y[j];
				t[++m].a=i;
				t[m].b=j;
				t[m].w=sqrt(xx*xx+yy*yy);
			}
		}
		sort(t+1,t+m+1);
		printf("%.2lf\n",mst());
	}
	return 0;
}
