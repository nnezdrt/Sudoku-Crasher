#include <algorithm>
#include <stdio.h>
#include <queue>
using namespace std;
#define maxn 1001
#define maxm 2000001
#define INF 0x7fffffff
int head[maxn],v[maxm],w[maxm],nex[maxm],all,n,m,num[maxn],dis[maxn];
bool used[maxn];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
inline void add(int a,int b,int c)
{
	v[++all]=b;w[all]=c;nex[all]=head[a];head[a]=all;
	v[++all]=a;w[all]=c;nex[all]=head[b];head[b]=all;
}
int dfs(int now)
{
	if (now==2)
		return num[2]=1;
	int temp=0;
	for (int i=head[now];i;i=nex[i])
	{
		int to=v[i];
		if (dis[to]>=dis[now])
			continue;
		if (num[to])
			temp+=num[to];
		else
			temp+=dfs(to);
	}
	return num[now]=temp;
}
int main()
{
	while (scanf("%d",&n),n)
	{
		all=0;
		int a,b,c;
		for (int i=1;i<=n;++i)
		{
			num[i]=head[i]=used[i]=0;
			dis[i]=INF;
		}
		num[2]=1;
		dis[2]=0;
		scanf("%d",&m);
		for (int i=1;i<=m;++i)
		{
			scanf("%d%d%d",&a,&b,&c);
			add(a,b,c);
		}
		q.push(make_pair(0,2));
		while (!q.empty())
		{
			int now=q.top().second;
			q.pop();
			if (used[now])
				continue;
			used[now]=1;
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
		printf("%d\n",dfs(1));
	}
	return 0;
}
