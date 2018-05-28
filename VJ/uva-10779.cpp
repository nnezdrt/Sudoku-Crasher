#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define maxn 11
#define maxm 40
#define INF 0x3f3f3f3f
int n,m,s,t,f[maxm][maxm],cap[maxm][maxm];
int maxFlow()
{
	int ret=0;
	while (1)
	{
		int pre[maxm]={0},r[maxm]={0},list[maxm]={1,1},top=1;
		r[1]=INF;
		while (top<=list[0])
		{
			int now=list[top++];
			for (int i=1;i<=t;++i)
			{
				if (cap[now][i]>f[now][i] && !r[i])
				{
					r[i]=min(r[now],cap[now][i]-f[now][i]);
					list[++list[0]]=i;
					pre[i]=now;
				}
			}
		}
		if (!r[t])
			break;
		ret+=r[t];
		for (int i=t;i!=1;i=pre[i])
		{
			int from=pre[i];
			f[from][i]+=r[t];
			f[i][from]-=r[t];
		}
	}
	return ret;
}
int main()
{
	int tt;
	scanf("%d",&tt);
	for (int cas=1;cas<=tt;++cas)
	{
		memset(f,0,sizeof(f));
		memset(cap,0,sizeof(cap));
		printf("Case #%d: ",cas);
		scanf("%d%d",&n,&m);
		s=1;
		t=n+m+1;
		int k,a;
		scanf("%d",&k);
		for (int i=1;i<=k;++i)
		{
			scanf("%d",&a);
			++cap[1][n+a];
		}
		for (int i=2;i<=n;++i)
		{
			int have[maxm]={0};
			scanf("%d",&k);
			for (int j=1;j<=k;++j)
			{
				scanf("%d",&a);
				++have[a];
			}
			for (int j=1;j<=m;++j)
			{
				if (!have[j])
					cap[n+j][i]=1;
				else if (have[j]>1) 
					cap[i][n+j]=have[j]-1;
			}
		}
		for (int i=1;i<=m;++i)
			cap[n+i][t]=1;
		printf("%d\n",maxFlow());
	}
	return 0;
}
