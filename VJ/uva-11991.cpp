//using vector,maybe using map is better
#include <cstdio>
#include <vector>
std::vector<int> ans[1000001];
int n,m;
int main()
{
	register int a,b;
	while (scanf("%d%d",&n,&m) == 2)
	{
		for (int i=1;i<=250000;++i)
		{
			ans[(i<<2)-3].clear();
			ans[(i<<2)-4].clear();
			ans[(i<<2)-1].clear();
			ans[(i<<2)].clear();
		}
		for (int i=1;i<=n;++i)
		{
			scanf("%d",&a);
			ans[a].push_back(i);
		}
		for (int i=1;i<=m;++i)
		{
			scanf("%d%d",&a,&b);
			if (ans[b].size() < a)
				printf("0\n");
			else
				printf("%d\n",ans[b][a-1]);
		}
	}
	return 0;
}
