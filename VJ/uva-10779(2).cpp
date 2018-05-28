#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define maxn 11
#define maxm 40
#define INF 0x3f3f3f3f
int n,m,s,t,cur[maxm],dis[maxm],f[maxm][maxm],cap[maxm][maxm];
bool bfs()
{
	memset(dis,0,sizeof(dis));
	int list[maxm]={1,1},top=1;
	dis[1]=1;
	while (top<=list[0])
	{
		int now=list[top++];
		for (int i=1;i<=t;++i)
		{
			if (!dis[i] && cap[now][i]>f[now][i])
			{
				dis[i]=dis[now]+1;
				list[++list[0]]=i;
			}
		}
	}
	return (bool)(dis[t]>0);
}
int dfs(int now,int flow)
{
	if (now==t || flow==0)
		return flow;
	int ff;
	for (int &i=cur[now];i<=t;++i)
	{
		if (dis[i]==dis[now]+1 && cap[now][i]>f[now][i] && (ff=dfs(i,min(flow,cap[now][i]-f[now][i]))))
		{
			f[now][i]+=ff;
			f[i][now]-=ff;
			return ff;
		}
	}
	return 0;
}
int maxFlow()
{
	int ret=0;
	while (bfs())
	{
		for (int i=1;i<=t;++i)
			cur[i]=1;
		ret+=dfs(1,INF);
	}
	return ret;
}
int main()
{
	//freopen("test.txt","r",stdin);
	int tt;
	scanf("%d",&tt);
	for (int cas=1;cas<=tt;++cas)
	{
		memset(f,0,sizeof(f));
		memset(cap,0,sizeof(cap));
		printf("Case #%d: ",cas);
		scanf("%d%d",&n,&m);
		s=1;
		t=n+m+1;
		int k,a;
		scanf("%d",&k);
		for (int i=1;i<=k;++i)
		{
			scanf("%d",&a);
			++cap[1][n+a];
		}
		for (int i=2;i<=n;++i)
		{
			int have[maxm]={0};
			scanf("%d",&k);
			for (int j=1;j<=k;++j)
			{
				scanf("%d",&a);
				++have[a];
			}
			for (int j=1;j<=m;++j)
			{
				if (!have[j])
					cap[n+j][i]=1;
				else if (have[j]>1) 
					cap[i][n+j]=have[j]-1;
			}
		}
		for (int i=1;i<=m;++i)
			cap[n+i][t]=1;
		printf("%d\n",maxFlow());
	}
	return 0;
}
