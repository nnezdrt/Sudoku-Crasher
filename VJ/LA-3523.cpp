#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <vector>
using namespace std;
#define maxn 1001
#define maxm 1000001
vector<int> q[maxn];
int n,m,s,low[maxn],vis[maxn],stack[maxm],g[maxn];
bool map[maxn][maxn],odd[maxn];
bool test(int from)
{
	bool flag=1,take[maxn]={0};
	int list[maxn]={1,from},color[maxn]={0},top=1;
	color[from]=1;
	while (top<=list[0])
	{
		int now=list[top++];
		if (take[now])
			continue;
		take[now]=1;
		for (int i=1;i<=n;++i)
		{
			if (map[now][i] || g[i]!=g[from])
				continue;
			if (!color[i])
			{
				color[i]=3-color[now];
				list[++list[0]]=i;
			}
			else if (color[i]==color[now])
				flag=0;
		}
	}
	if (!flag)
		for (int i=1;i<=list[0];++i)
			odd[list[i]]=1;
}
bool dfs(int now,int fa)
{
	int son=0;
	low[now]=vis[now]=++s;
	for (int i=1;i<=n;++i)
	{
		if (map[now][i])
			continue;
		if (!vis[i])
		{
			++son;
			stack[++stack[0]]=now*1000+i;
			dfs(i,now);
			low[now]=min(low[now],low[i]);
			if (low[i]>=vis[now])
			{
				q[++g[0]].clear();
				while (1)
				{
					int temp=stack[stack[0]--];
					int x=temp/1000,y=temp%1000;
					if (g[x]!=g[0])
						q[g[0]].push_back(x);
					if (g[y]!=g[0])
						q[g[0]].push_back(y);
					g[x]=g[y]=g[0];
					if (now==x && i==y)
						break;
				}
			}
		}
		else if (vis[i]<vis[now] && i!=fa)
		{
			low[now]=min(low[now],vis[i]);
			stack[++stack[0]]=now*1000+i;
		}
	}
}
int main()
{
	while (scanf("%d%d",&n,&m),n)
	{
		memset(map,0,sizeof(map));
		int ans=0;
		for (int i=1;i<=n;++i)
		{
			map[i][i]=1;
			odd[i]=g[i]=vis[i]=low[i]=0;
		}
		s=g[0]=stack[0]=0;
		while (m--)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			map[x][y]=map[y][x]=1;
		}
		for (int i=1;i<=n;++i)
			if (!vis[i])
				dfs(i,0);
		for (int i=1;i<=g[0];++i)
		{
			for (int j=0;j<q[i].size();++j)
				g[q[i][j]]=i;
			test(q[i][1]);
		}
		for (int i=1;i<=n;++i)
			if (!odd[i])
				++ans;
		printf("%d\n",ans);
	}
	return 0;
}
