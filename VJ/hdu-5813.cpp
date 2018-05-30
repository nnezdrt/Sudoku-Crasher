#include <algorithm>
#include <stdio.h>
using namespace std;
#define maxn 1001
int n,m,t,cas;
struct node
{
	int c,num;
	bool operator<(const node &x)const
	{return c<x.c;}
}a[maxn];
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		printf("Case #%d: ",++cas);
		scanf("%d",&n);
		int ans=0;
		bool flag=1;
		for (int i=1;i<=n;++i)
		{
			scanf("%d",&a[i].c);
			a[i].num=i;
			ans+=a[i].c;
		}
		sort(a+1,a+n+1);
		for (int i=1;i<=n;++i)
			if (i<=a[i].c)
				flag=0;
		if (flag)
		{
			printf("Yes\n%d\n",ans);
			for (int i=1;i<=n;++i)
				for (int j=1;j<=a[i].c;++j)
					printf("%d %d\n",a[i].num,a[j].num);
		}
		else
			printf("No\n");
	}
	return 0;
}
