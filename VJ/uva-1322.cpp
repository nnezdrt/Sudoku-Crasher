#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int f[140001],t,n,m,ql,qr,k;
void update(int now,int nowl,int nowr)
{
	if (nowl!=nowr)
	{
		int mid=(nowl+nowr)/2;
		if (qr<=mid)
			update(now<<1,nowl,mid);
		else
			update(now<<1|1,mid+1,nowr);
	}
	f[now]=min(k+1,f[now]);
}
int ask(int now,int nowl,int nowr)
{
	if (ql<=nowl && nowr<=qr)
		return f[now];
	int mid=(nowl+nowr)/2;
	if (ql>mid)
		return ask(now<<1|1,mid+1,nowr);
	if (qr<=mid)
		return ask(now<<1,nowl,mid);
	int l=ask(now<<1,nowl,mid),r=ask(now<<1|1,mid+1,nowr);
	return min(l,r);
}
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d",&n,&m);
		memset(f,127,sizeof(f));
		k=-1;
		update(qr=1,1,n);
		while (m--)
		{
			scanf("%d%d",&ql,&qr);
			k=ask(1,1,n);
			update(1,1,n);
		}
		printf("%d\n",ask(1,1,ql=qr=n));
		if (t)
			printf("\n");
	}
	return 0;
}
