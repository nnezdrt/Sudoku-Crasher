#include <algorithm>
#include <stdio.h>
using namespace std;
#define maxn 1001
int n,m,t,a[maxn],b[maxn],l[maxn],r[maxn];
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d",&n,&m);
		int hash[maxn]={0},num[maxn]={0};
		bool flag=1;
		for (int i=1;i<=n;++i)
		{
			scanf("%d",&a[i]);
			++hash[a[i]];
		}
		for (int i=1;i<=n;++i)
		{
			scanf("%d",&b[i]);
			--hash[b[i]];
		}
		for (int i=1;i<=m;++i)
			scanf("%d%d",&l[i],&r[i]);
		for (int i=0;i<=n;++i)
			if (hash[i])
				flag=0;
		if (!flag)
		{
			printf("No\n");
			continue;
		}
		for (int i=1;i<=n;++i)
		{
			for (int j=1;j<=n;++j)
				if (a[j]==b[i] && !num[j])
				{
					num[j]=i;
					break;
				}
		}
		for (int i=1;i<=m;++i)
			sort(num+l[i],num+r[i]+1);
		for (int i=1;i<=n;++i)
			if (num[i]!=i)
				flag=0;
		printf("%s\n",flag?"Yes":"No");
	}
	return 0;
}
