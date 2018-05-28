#include <algorithm>
#include <stdio.h>
using namespace std;
#define maxn 100001
int n,m,cnt,k,cash;
int main()
{
	while (~scanf("%d",&cash))
	{
		scanf("%d",&n);
		bool dp[maxn]={1}; //dp[0]=1
		int ans=0; //ans默认为0
		while (n--)
		{
			int used[maxn]={0}; //used[0]=0,这样就不用memset了
			//used[i]只记录当前面值在i元时的使用情况，因为其他的面额不需要关心
			scanf("%d%d",&cnt,&k);
			m=cash-k;
			for (int i=0;i<=m;++i)
			{
				if (dp[i] && used[i]<cnt) //访问到了i元钱并且还能花钱
				{
					if (!dp[i+k]) //i+k元没有出现过
					{
						dp[i+k]=1; //标记访问
						ans=max(ans,i+k); //更新答案
						used[i+k]=used[i]+1; //更新使用的张数
					}
					else if (used[i+k]>used[i]+1) //出现过了但是能花更少张的票子则更新-_-
						used[i+k]=used[i]+1;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
