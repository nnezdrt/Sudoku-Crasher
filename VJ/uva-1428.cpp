#include <stdio.h>
#include <string.h>
#define maxn 20001
#define maxm 100001
int n,t,a[maxn],f[maxm];
inline int lowbit(int x)
{return x&(-x);}
void add(int pos)
{
	while (pos<maxm)
	{
		++f[pos];
		pos+=lowbit(pos);
	}
}
int getsum(int pos)
{
	int s=0;
	while (pos)
	{
		s+=f[pos];
		pos-=lowbit(pos);
	}
	return s;
}
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		memset(f,0,sizeof(f));
		long long ans=0;
		int l[maxn]={0},r[maxn]={0};
		for (int i=1;i<=n;++i)
		{
			scanf("%d",&a[i]);
			add(a[i]);
			l[i]=getsum(a[i])-1;
		}
		for (int i=2;i<n;++i)
		{
			r[i]=getsum(a[i])-1-l[i];
			ans+=l[i]*(n-i-r[i])+r[i]*(i-1-l[i]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
