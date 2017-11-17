#include <cstdio>
int n,tick,list[17]={0,1};
bool isPrime[32]={0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1};
bool used[17];
void dfs(int now)
{
	if (now == n+1)
	{
		if (isPrime[list[1]+list[n]])
		{
			printf("%d",list[1]);
			for (int i=2;i<=n;++i)
				printf(" %d",list[i]);
			printf("\n");
		}
		return;
	}
	for (int i=2;i<=n;++i)
		if (!used[i] && isPrime[i+list[now-1]])
		{
			used[i]=1;
			list[now]=i;
			dfs(now+1);
			used[i]=0;
		}
}
int main()
{
	scanf("%d",&n);
	printf("Case %d:\n",++tick);
	dfs(2);
	while (scanf("%d",&n) == 1)
	{
		printf("\nCase %d:\n",++tick);
		dfs(2);
	}
	return 0;
}
