#include <algorithm>
#include <stdio.h>
using namespace std;
#define maxn 100001
#define maxm 1000001
struct noo
{
	int w,a,b;
	bool operator <(const noo& x)const
	{return w<x.w;}
}e[maxm];
int n,m,T,fa[maxn];
int head[maxn],v[maxm],w[maxm],nex[maxm],all;
long long ans1;
double ans2;
int getfa(int x)
{return x==fa[x]?x:fa[x]=getfa(fa[x]);}
inline void add(int a,int b,int c)
{
	v[++all]=b;
	w[all]=c;
	nex[all]=head[a];
	head[a]=all;
}
int dfs(int now,int f)
{
	int tick=0;
	for (int i=head[now];i;i=nex[i])
	{
		int to=v[i];
		if (to==f)
			continue;
		int temp=dfs(to,now);
		tick+=temp;
		ans2+=(double)1.0*temp*(n-temp)*w[i];
	}
	return tick+1;
}
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		int tick=0;
		ans1=ans2=all=0;
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n;++i)
		{
			head[i]=0;
			fa[i]=i;
		}
		for (int i=1;i<=m;++i)
			scanf("%d%d%d",&e[i].a,&e[i].b,&e[i].w);
		sort(e+1,e+m+1);
		for (int i=1;i<=m;++i)
		{
			int a=getfa(e[i].a),b=getfa(e[i].b);
			if (a-b)
			{
				fa[a]=b;
				ans1+=e[i].w;
				add(e[i].a,e[i].b,e[i].w);
				add(e[i].b,e[i].a,e[i].w);
				if (++tick==n-1)
					break;
			}
		}
		dfs(1,0);
		printf("%lld %.2lf\n",ans1,ans2/n/(n-1)*2);
	}
	return 0;
}
