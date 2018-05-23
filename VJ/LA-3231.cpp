#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <queue>
#include <map>
using namespace std;
#define abs(x) ((x)<0?(-(x)):(x))
#define maxn 11005
#define maxm 70001
#define INF 0x3f3f3f3f
vector<int>e[maxn];
map<int,int>f[maxn],tempf[maxn];
int n,m,dis[maxn],cur[maxn],s,t;
inline void add(int a,int b,int c)
{
	e[a].push_back(b);f[a][b]=tempf[a][b]=c;
	e[b].push_back(a);f[b][a]=tempf[b][a]=0;
}
bool bfs()
{
	memset(dis,0,sizeof(dis));
	dis[0]=1;
	queue<int>q;
	q.push(0);
	while (!q.empty())
	{
		int now=q.front();
		q.pop();
		for (int i=0;i<e[now].size();++i)
		{
			int to=e[now][i];
			if (!dis[to] && f[now][to])
			{
				dis[to]=dis[now]+1;
				q.push(to);
			}
		}
	}
	return dis[t];
}
int dfs(int from,int flow)
{
	if (from==t || flow==0)
		return flow;
	for (int &i=cur[from];i<e[from].size();++i)
	{
		int to=e[from][i];
		if (dis[to]==dis[from]+1 && f[from][to])
		{
			int d=dfs(to,min(flow,f[from][to]));
			if (!d)
				continue;
			f[from][to]-=d;
			f[to][from]+=d;
			return d;
		}
	}
	return 0;
}
bool dinic(int nowFlow)
{
	int ret=0;
	for (int i=1;i<=n;++i)
		tempf[m+i][t]=nowFlow;
	for (int i=0;i<=t;++i)
	{
		for (int j=0;j<e[i].size();++j)
		{
			int to=e[i][j];
			f[i][to]=tempf[i][to];
		}
	}
	while (1)
	{
		if (!bfs())return (ret==m);
		memset(cur,0,sizeof(cur));
		int temp;
		while ((temp=dfs(0,INF))>0)ret+=temp;
	}
	return (ret==m);
}
int main()
{
	//freopen("test.txt","r",stdin);
	int T,a,b;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&m);
		for (int i=0;i<=n+m+1;++i)
		{
			e[i].clear();
			f[i].clear();
			tempf[i].clear();
		}
		s=0;
		t=n+m+1;
		for (int i=1;i<=m;++i)
			add(s,i,1);
		for (int i=1;i<=m;++i)
		{
			scanf("%d%d",&a,&b);
			add(i,m+a,1);
			add(i,m+b,1);
		}
		for (int i=1;i<=n;++i)
			add(m+i,t,1);
		int l=1,r=m,mid;
		while (l<r)
		{
			mid=l+r>>1;
			if (dinic(mid))
				r=mid;
			else
				l=mid+1;
		}
		printf("%d\n",l);
	}
	return 0;
}
