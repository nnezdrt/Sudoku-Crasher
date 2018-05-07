#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <queue>
using namespace std;
#define maxn 101
#define maxm 3601
#define INF 0x7fffffff
int head[6*maxn],v[maxm],w[maxm],nex[maxm],all;
int n,m,k,c[maxn];
bool used[6*maxn];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
inline void add(int a,int b,int cc)
{
	v[++all]=b;w[all]=cc;nex[all]=head[a];head[a]=all;
	v[++all]=a;w[all]=cc;nex[all]=head[b];head[b]=all;
}
void dij()
{
	int dis[6*maxn];
	bool usedd[6*maxn]={0};
	for (int i=1;i<6*maxn;++i)
		dis[i]=INF;
	for (int i=1;i<=n;++i)
		q.push(make_pair(dis[i*100]=0,i*100));
	while (!q.empty())
	{
		int now=q.top().second;
		q.pop();
		if (usedd[now])
			continue;
		usedd[now]=1;
		for (int i=head[now];i;i=nex[i])
		{
			int to=v[i];
			if (!usedd[to] && dis[to]>dis[now]+w[i])
			{
				dis[to]=dis[now]+w[i];
				q.push(make_pair(dis[to],to));
			}
		}
	}
	int ans=INF;
	for (int i=1;i<=n;++i)
		ans=min(ans,dis[i*100+k]);
	if (ans==INF)
		printf("IMPOSSIBLE\n");
	else
		printf("%d\n",ans);
}
int main()
{
	int temp,ch,last,i,j;
	while (~scanf("%d%d",&n,&k))
	{
		all=0;
		memset(head,0,sizeof(head));
		memset(used,0,sizeof(used));
		for (i=1;i<=n;++i)
			scanf("%d",&c[i]);
		getchar();
		for (i=1;i<=n;++i)
		{
			ch=1;
			last=-1;
			while (ch!='\n')
			{
				temp=0;
				ch=getchar();
				while (ch!=' ' && ch!='\n')
				{
					temp=temp*10+ch-'0';
					ch=getchar();
				}
				if (last!=-1)
					add(i*100+last,i*100+temp,(temp-last)*c[i]);
				last=temp;
				used[i*100+temp]=1;
				for (j=i-1;j>=1;--j)
					if (used[j*100+temp])
						add(j*100+temp,i*100+temp,60);
			}
		}
		dij();
	}
	return 0;
}
