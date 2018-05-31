#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define maxn 210
#define maxm 85001
#define INF 0x7fffffff
long long head[maxn],u[maxm],v[maxm],f[maxm],w[maxm],nex[maxm],all;
int n,m,k,ax,an,bx,bn,e,list[maxm];
long long ans;
inline void add(int a,int b,long long c,long long cc)
{
	u[all]=a;v[all]=b;f[all]=c;w[all]=cc;nex[all]=head[a];head[a]=all++;
	u[all]=b;v[all]=a;f[all]=0;w[all]=-cc;nex[all]=head[b];head[b]=all++;
}
void spfa()
{
	while (1)
	{
		long long pre[maxn],dis[maxn],flow[maxn]={0};
		bool used[maxn]={0};
		int ss=1,top=1;
		for (int i=0;i<=n;++i)
		{
			pre[i]=-1;
			dis[i]=INF;
		}
		dis[0]=list[1]=0;
		flow[0]=INF;
		while (top<=ss)
		{
			int now=list[top++];
			used[now]=0;
			for (int i=head[now];i+1;i=nex[i])
			{
				int to=v[i];
				if (f[i] && dis[to]>dis[now]+w[i])
				{
					pre[to]=i;
					dis[to]=dis[now]+w[i];
					flow[to]=min(flow[now],f[i]);
					if (!used[to])
					{
						used[to]=1;
						list[++ss]=to;
					}
				}
			}
		}
		if (dis[n]>=0)
			return;
		ans+=dis[n]*flow[n];
		for (int i=pre[n];i+1;i=pre[u[i]])
		{
			f[i]-=flow[n];
			f[i^1]+=flow[n];
		}
	}
}
int main()
{
	int cas=0,tt;
	scanf("%d",&tt);
	while (tt--)
	{
		scanf("%d%d",&m,&k);
		memset(head,-1,sizeof(head));
		n=m+m+1;
		ans=all=0;
		for (int i=1;i<=m;++i)
		{
			scanf("%d%d%d%d%d",&ax,&an,&bx,&bn,&e);
			add(0,i,an,ax);
			add(i+m,n,bn,-bx);
			for (int j=0;j<=e && m+j+i<n;++j)
				add(i,m+i+j,INF,j*k);
		}
		spfa();
		printf("Case %d: %lld\n",++cas,-ans);
	};
	return 0;
}
