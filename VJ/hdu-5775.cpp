#include <algorithm>
#include <stdio.h>
using namespace std;
#define abs(x) ((x)<0?(-(x)):(x))
#define maxn 100001
int n,m,T,c[maxn],ans[maxn];
int lowbit(int x)
{return x&(-x);}
int getsum(int pos)
{
	int s=0;
	while (pos)
	{
		s+=c[pos];
		pos-=lowbit(pos);
	}
	return s;
}
void update(int pos,int delta)
{
	while (pos<=n)
	{
		c[pos]+=delta;
		pos+=lowbit(pos);
	}
}
int main()
{
	scanf("%d",&T);
	for (int tt=1;tt<=T;++tt)
	{
		for (int i=1;i<=n;++i)
			c[i]=0;
		int a;
		printf("Case #%d:",tt);
		scanf("%d",&n);
		for (int i=1;i<=n;++i)
		{
			scanf("%d",&a);
			update(a,1);
			int s=getsum(a-1);
			ans[a]=max(a-1-s,i-1-s);
		}
		for (int i=1;i<=n;++i)
			printf(" %d",ans[i]);
		printf("\n");
	}
	return 0;
}
