#include <stdio.h>
#include <string.h>
#define min(a,b) ((a)<(b)?(a):(b))
#define maxn 51
#define maxm 2001
#define INF 0x7fffffff
int head[maxn],u[maxm],v[maxm],w[maxm],next[maxm],all;
int n,m,r[maxn];
inline void add(int a,int b,int c)
{
	u[all]=a;v[all]=b;w[all]=c;
	next[all]=head[a];
	head[a]=all++;
}
void bfs()
{
	while (1)
	{
		int last[maxn],list[maxn]={1,1},top=1,now;
		memset(last,-1,sizeof(last));
		memset(r,0,sizeof(r));
		r[1]=INF;
		while (top<=list[0])
		{
			now=list[top++];
			for (int i=head[now];i+1;i=next[i])
			{
				int to=v[i];
				if (!r[to] && w[i])
				{
					r[to]=min(r[now],w[i]);
					last[to]=i;
					list[++list[0]]=to;
				}
			}
		}
		if (!r[2])
			break;
		for (int i=last[2];v[i]-1 && i+1;i=last[u[i]])
		{
			w[i]-=r[2];
			w[i^1]+=r[2];
		}
	}
}
int main()
{
	while (scanf("%d%d",&n,&m),n)
	{
		all=0;
		memset(head,-1,sizeof(head));
		int x,y,z;
		while (m--)
		{
			scanf("%d%d%d",&x,&y,&z);
			add(x,y,z);add(y,x,0);
			add(y,x,z);add(x,y,0);
		}
		bfs();
		for (int i=0;i<all;i+=4)
			if ((r[u[i]] && !r[v[i]]) || (!r[u[i]] && r[v[i]]))
				printf("%d %d\n",u[i],v[i]);
		printf("\n");
	}
	return 0;
}
