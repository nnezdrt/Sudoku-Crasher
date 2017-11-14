#include <cstdio>
#include <cstring>
using namespace std;
int t,n;
int a[50001],c[50001];
char s[8];
int lowb(int x)
{
	return x&(-x);
}
int sum(int x)
{
	int s=0;
	while (x)
	{
		s+=c[x];
		x-=lowb(x);
	}
	return s;
}
void change(int pos,int delta)
{
	while (pos<=n)
	{
		c[pos]+=delta;
		pos+=lowb(pos);
	}
}
int main()
{
	scanf("%d",&t);
	int temp=t;
	while (temp--)
	{
		printf("Case %d:\n",t-temp);
		memset(a,0,sizeof(a));
		memset(c,0,sizeof(c));
		scanf("%d",&n);
		for (int i=1;i<=n;++i)
		{
			scanf("%d",&a[i]);
			change(i,a[i]);
		}
		while (scanf("%s",s) == 1)
		{
			if (s[0]=='E')
				break;
			int ta,tb;
			scanf("%d%d",&ta,&tb);
			if (s[0]=='Q')
			{
				printf("%d\n",sum(tb)-sum(ta-1));
			}
			else
			{
				if (s[0]=='S')
					tb=-tb;
				change(ta,tb);
			}
		}
	}
	return 0;
}
