#include <stdio.h>
#define min(a,b) ((a)<(b)?(a):(b))
#define maxn 405
#define INF 99999999

int map[maxn][maxn];
int n,f,d,ans;

void bfs(int from,int to)
{
	n=f+n+n+d+2;
	while (1)
	{
		int list[maxn]={1,from},last[maxn]={0},r[maxn]={0},now,top=1;
		r[from]=INF;
		while (top<=list[0])
		{
			now=list[top++];
			for (int i=1;i<=n;++i)
				if (map[now][i] && !r[i])
				{
					last[i]=now;
					r[i]=min(r[now],map[now][i]);
					list[++list[0]]=i;
				}
		}
		if (!r[to])
			break;
		for (int i=to;i!=from;i=last[i])
		{
			map[last[i]][i]-=r[to];
			map[i][last[i]]+=r[to];
		}
		++ans;
	}
}

int main()
{
	int x,xf,xd;
	scanf("%d%d%d",&n,&f,&d);
	for (int i=1;i<=n;++i)
	{
		scanf("%d%d",&xf,&xd);
		for (int j=1;j<=xf;++j)
		{
			scanf("%d",&x);
			map[x][f+i]=1;
		}
		for (int j=1;j<=xd;++j)
		{
			scanf("%d",&x);
			map[f+n+i][x+f+n+n]=1;
		}
		map[f+i][f+n+i]=1;
	}
	int temp=f+n+n+d+1;
	for (int i=1;i<=f;++i)
		map[temp][i]=1;
	for (int i=1;i<=d;++i)
		map[f+n+n+i][temp+1]=1;
	bfs(f+n+n+d+1,f+n+n+d+2);
	printf("%d\n",ans);
	return 0;
}
