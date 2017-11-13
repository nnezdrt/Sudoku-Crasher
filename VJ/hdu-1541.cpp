#include <cstdio>
#include <cstring>
using namespace std;
int c[32002],ans[15001],n;
int lowb(int x)
{
	return x&(-x);
}
int sum(int x)
{
	int s=0;
	while (x>0)
	{
		s+=c[x];
		x-=lowb(x);
	}
	return s;
}
void change(int pos,int delta)
{
	while (pos<=32001)
	{
		c[pos]+=delta;
		pos+=lowb(pos);
	}
}
int main()
{
	int temp;
	while (scanf("%d",&n) == 1)
	{
		memset(c,0,sizeof(c));
		memset(ans,0,sizeof(ans));
		for (int i=1;i<=n;++i)
		{
			scanf("%d",&temp);
			change(temp+1,1);
			++ans[sum(temp+1)-1];
			scanf("%d",&temp);
		}
		for (int i=0;i<n;++i)
			printf("%d\n",ans[i]);
	}
	return 0;
}
