#include <stdio.h>
#include <algorithm>
using namespace std;
#define maxn 500001
#define maxm 1250000
struct node
{
	long long v;
	int l,r;
	node(long long _v=0,int _l=0,int _r=0)
	{
		l=_l;
		r=_r;
		v=_v;
	}
	bool operator <(const node& x)const
	{
		if (v!=x.v)
			return v<x.v;
		return (l==x.l?r>x.r:l>x.l);
	}
}sub[maxm],suf[maxm],pre[maxm];
int n,m,ql,qr,t,a[maxn];
long long s[maxn];
void build(int now,int nowl,int nowr)
{
	if (nowl==nowr)
	{
		sub[now].l=pre[now].l=suf[now].l=nowl;
		sub[now].r=pre[now].r=suf[now].r=nowr;
		sub[now].v=pre[now].v=suf[now].v=s[nowl]-s[nowl-1];
		return;
	}
	int mid=(nowl+nowr)/2,ll=now<<1,rr=now<<1|1;
	build(now<<1,nowl,mid);
	build(now<<1|1,mid+1,nowr);
	pre[now]=max(node(s[mid]-s[nowl-1]+pre[rr].v,nowl,pre[rr].r),pre[ll]);
	suf[now]=max(node(s[nowr]-s[mid]+suf[ll].v,suf[ll].l,nowr),suf[rr]);
	sub[now]=max(sub[ll],sub[rr]);
	sub[now]=max(sub[now],node(suf[ll].v+pre[rr].v,suf[ll].l,pre[rr].r));
}
node askpre(int now,int nowl,int nowr)
{
	if (ql<=nowl && nowr<=qr)
		return pre[now];
	int mid=(nowl+nowr)/2;
	if (ql>mid)
		return askpre(now<<1|1,mid+1,nowr);
	if (qr<=mid)
		return askpre(now<<1,nowl,mid);
	node nr=askpre(now<<1|1,mid+1,nowr);
	return max(node(s[mid]-s[nowl-1]+nr.v,max(ql,nowl),nr.r),askpre(now<<1,nowl,mid));
}
node asksuf(int now,int nowl,int nowr)
{
	if (ql<=nowl && nowr<=qr)
		return suf[now];
	int mid=(nowl+nowr)/2;
	if (ql>mid)
		return asksuf(now<<1|1,mid+1,nowr);
	if (qr<=mid)
		return asksuf(now<<1,nowl,mid);
	node nl=asksuf(now<<1,nowl,mid);
	return max(node(s[nowr]-s[mid]+nl.v,nl.l,min(qr,nowr)),asksuf(now<<1|1,mid+1,nowr));
}
node asksub(int now,int nowl,int nowr)
{
	if (ql<=nowl && nowr<=qr)
		return sub[now];
	int mid=(nowl+nowr)/2;
	if (ql>mid)
		return asksub(now<<1|1,mid+1,nowr);
	if (qr<=mid)
		return asksub(now<<1,nowl,mid);
	node nl=asksuf(now<<1,nowl,mid),nr=askpre(now<<1|1,mid+1,nowr);
	return max(node(nl.v+nr.v,nl.l,nr.r),max(asksub(now<<1,nowl,mid),asksub(now<<1|1,mid+1,nowr)));
}
int main()
{
	while (~scanf("%d%d",&n,&m))
	{
		printf("Case %d:\n",++t);
		int temp;
		for (int i=1;i<=n;++i)
		{
			scanf("%d",&temp);
			s[i]=s[i-1]+temp;
		}
		build(1,1,n);
		while (m--)
		{
			scanf("%d%d",&ql,&qr);
			node ans=asksub(1,1,n);
			printf("%d %d\n",ans.l,ans.r);
		}
	}
	return 0;
}
