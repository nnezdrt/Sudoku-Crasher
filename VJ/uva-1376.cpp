#include <algorithm>
#include <stdio.h>
#include <queue>
using namespace std;
#define maxn 2000005
#define maxm 6000015
#define INF 0x7fffffff
int head[maxn],v[maxm],w[maxm],nex[maxm],all;
int n,m,s,dis[maxn];
bool used[maxn];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
inline void add(int a,int b,int c)
{
	v[++all]=b;w[all]=c;nex[all]=head[a];head[a]=all;
	v[++all]=a;w[all]=c;nex[all]=head[b];head[b]=all;
}
int dij()
{
	q.push(make_pair(0,1));
	while (!q.empty())
	{
		int now=q.top().second;
		q.pop();
		if (used[now])
			continue;
		for (int i=head[now];i;i=nex[i])
		{
			int to=v[i];
			if (!used[to] && dis[to]>dis[now]+w[i])
			{
				dis[to]=dis[now]+w[i];
				q.push(make_pair(dis[to],to));
			}
		}
	}
	return dis[s];
}
int main()
{
	int tick=0,i,j,temp;
	while (scanf("%d%d",&n,&m),n)
	{
		s=(n-1)*(m-1)*2+2;
		for (i=1;i<=s;++i)
		{
			head[i]=used[i]=0;
			dis[i]=INF;
		}
		dis[1]=all=0;
		for (i=1;i<m;++i)
		{
			scanf("%d",&temp);
			add(1,i+i+1,temp);
		}
		for (i=2;i<n;++i)
		{
			for (j=1;j<m;++j)
			{
				scanf("%d",&temp);
				add((i-2)*2*(m-1)+j+j,(i-1)*2*(m-1)+j+j+1,temp);
			}
		}
		for (i=1;i<m;++i)
		{
			scanf("%d",&temp);
			add(s,(n-2)*2*(m-1)+i+i,temp);
		}
		for (i=1;i<n;++i)
		{
			scanf("%d",&temp);
			add(s,(i-1)*(m-1)*2+2,temp);
			for (j=2;j<m;++j)
			{
				scanf("%d",&temp);
				add((i-1)*2*(m-1)+j+j,(i-1)*2*(m-1)+j+j-1,temp);
			}
			scanf("%d",&temp);
			add(1,i*2*(m-1)+1,temp);
		}
		for (i=1;i<n;++i)
			for (j=1;j<m;++j)
			{
				scanf("%d",&temp);
				add((i-1)*(m-1)*2+j+j,(i-1)*(m-1)*2+j+j+1,temp);
			}
		printf("Case %d: Minimum = %d\n",++tick,dij());
	}
	return 0;
}
