#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define maxn 2505
#define maxm 250000
#define INF 0x7fffffff
int head[maxn],u[maxm],v[maxm],f[maxm],nex[maxm],all;
int n,m,d,ff,b,s,t,map[maxn][maxn],list[maxn],dis[maxn],cur[maxn];
inline void add(int a,int b,int c)
{
	u[all]=a;v[all]=b;f[all]=c;nex[all]=head[a];head[a]=all++;
	u[all]=b;v[all]=a;f[all]=0;nex[all]=head[b];head[b]=all++;
}
bool bfs()
{
	memset(dis,0,sizeof(dis));
	int top=1,ss=1;
	dis[0]=1;
	while (top<=ss)
	{
		int ff,now=list[top++];
		for (int i=head[now];i+1;i=nex[i])
		{
			int to=v[i];
			if (!dis[to] && f[i])
			{
				dis[to]=dis[now]+1;
				list[++ss]=to;
			}
		}
	}
	return dis[t];
}
int dfs(int now,int a)
{
	if (now==t || a==0)
		return a;
	int flow=0;
	for (int &i=cur[now];i+1;i=nex[i])
	{
		int to=v[i];
		if (dis[to]==dis[now]+1 && (ff=dfs(to,min(a,f[i]))))
		{
			flow+=ff;
			a-=ff;
			f[i]-=ff;
			f[i^1]+=ff;
			if (!a)
				return flow;
		}
	}
	return flow;
}
int maxFlow()
{
	int ret=0;
	while (bfs())
	{
		for (int i=s;i<=t;++i)
			cur[i]=head[i];
		ret+=dfs(s,INF);
	}
	return ret;
}
int main()
{
	int T,tick,temp;
	char ch;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d%d%d%d",&m,&n,&d,&ff,&b);
		getchar();
		memset(head,-1,sizeof(head));
		temp=tick=all=0;
		t=n*m+1;
		for (int i=1;i<=n;++i)
		{
			for (int j=1;j<=m;++j)
			{
				++tick;
				ch=getchar();
				if (ch=='.')
					map[i][j]=0;
				else
					map[i][j]=1;
				if (i==1 || j==1 || i==n || j==m)
				{
					if (!map[i][j])
					{
						map[i][j]=1;
						temp+=ff;
					}
					add(s,tick,INF);
				}
				else
				{
					if (map[i][j])
						add(s,tick,d);
					else
						add(tick,t,ff);
				}
				if (i>1)
					add(tick,tick-m,b);
				if (i<n)
					add(tick,tick+m,b);
				if (j>1)
					add(tick,tick-1,b);
				if (j<m)
					add(tick,tick+1,b);
			}
			getchar();
		}
		printf("%d\n",temp+maxFlow());
	}
	return 0;
}
