#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <vector>
using namespace std;
#define maxn 100001
#define maxm 100001
int low[maxn],vis[maxn],stack[maxn],g,s;
int n,m,head[maxn],u[maxm],v[maxm],nex[maxm],all;
long long ans1,ans2;
bool cut[maxn];
vector<int> q[maxn];
inline void add(int a,int b)
{
	u[++all]=a;v[all]=b;nex[all]=head[a];head[a]=all;
	u[++all]=b;v[all]=a;nex[all]=head[b];head[b]=all;
}
void dfs(int now,int fa)
{
	vis[now]=low[now]=++s;
	stack[++stack[0]]=now;
	int son=0;
	for (int i=head[now];i;i=nex[i])
	{
		int to=v[i];
		if (fa==to)
			continue;
		if (!vis[to])
		{
			++son;
			dfs(to,now);
			low[now]=min(low[now],low[to]);
			if (low[to]>=vis[now])
			{
				cut[now]=1;
				q[++g].clear();
				while (1)
				{
					int vv=stack[stack[0]--];
					q[g].push_back(vv);
					if (vv==to)
						break;
				}
				q[g].push_back(now);
			}
		}
		else
			low[now]=min(low[now],vis[to]);
	}
	if (!fa && son<2)
		cut[now]=0;
}
int main()
{
	//freopen("test.txt","r",stdin);
	int a,b,tt=0;
	while (scanf("%d",&m),m)
	{
		printf("Case %d: ",++tt);
		ans1=s=n=all=g=0;
		ans2=1;
		memset(head,0,sizeof(head));
		while (m--)
		{
			scanf("%d%d",&a,&b);
			n=max(n,max(a,b));
			add(a,b);
		}
		for (int i=1;i<=n;++i)
			cut[i]=low[i]=vis[i]=0;
		for (int i=1;i<=n;++i)
			if (!vis[i])
				dfs(i,0);
		if (g==1)
		{
			printf("2 %lld\n",(long long)n*(n-1)/2);
			continue;
		}
		for (int i=1;i<=g;++i)
		{
			int tick=0,temp=q[i].size();
			for (int j=0;j<temp;++j)
				if (cut[q[i][j]])
					++tick;
			if (tick==1)
			{
				++ans1;
				ans2*=(long long)temp-1;
			}
		}
		printf("%lld %lld\n",ans1,ans2);
	}
	return 0;
}
