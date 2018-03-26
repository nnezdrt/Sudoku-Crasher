#include <stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define INF 999999999
#define maxn 301
bool usedx[maxn],usedy[maxn];
int lx[maxn],ly[maxn],w[maxn][maxn],match[maxn];
int n;
bool dfs(int now)
{
	usedx[now]=1;
	for (int i=1;i<=n;++i)
	{
		if (!usedy[i] && lx[now]+ly[i]==w[now][i])
		{
			usedy[i]=1;
			if (!match[i] || dfs(match[i]))
			{
				match[i]=now;
				return 1;
			}
		}
	}
	return 0;
}
int km()
{
	int ret=0;
	for (int i=1;i<=n;++i)
	{
		while (1)
		{
			for (int j=0;j<=n;++j)
				usedx[j]=usedy[j]=0;
			if (dfs(i))
				break;
			int d=INF;
			for (int i=1;i<=n;++i)
				if (usedx[i])
					for (int j=1;j<=n;++j)
						if (!usedy[j])
							d=min(d,lx[i]+ly[j]-w[i][j]);
			for (int i=1;i<=n;++i)
			{
				if (usedx[i])
					lx[i]-=d;
				if (usedy[i])
					ly[i]+=d;
			}
		}
	}
	for (int i=1;i<=n;++i)
		if (match[i])
			ret+=w[match[i]][i];
	return ret;
}
int main()
{
	while (~scanf("%d",&n))
	{
		for (int i=1;i<=n;++i)
		{
			match[i]=lx[i]=ly[i]=0;
			for (int j=1;j<=n;++j)
			{
				scanf("%d",&w[i][j]);
				lx[i]=max(lx[i],w[i][j]);
			}
		}
		printf("%d\n",km());
	}
	return 0;
}
