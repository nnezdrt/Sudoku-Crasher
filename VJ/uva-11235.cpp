#include <stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define maxn 100001
int l[maxn],r[maxn],seg[maxn],f[maxn][18],n,m;
void preDeal()
{
	for (int j=1;(1<<j)<=seg[0];++j)
		for (int i=1;i+(1<<j)-1<=seg[0];++i)
			f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
}
int rmq(int left,int right)
{
	int k=-1,s=(right-left+1);
	while (s)
	{
		++k;
		s/=2;
	}
	return max(f[left][k],f[right-(1<<k)+1][k]);
}
int main()
{
	while (scanf("%d",&n),n)
	{
		scanf("%d",&m);
		seg[0]=0;
		int temp,last=-1000000;
		for (int i=1;i<=n;++i)
		{
			scanf("%d",&temp);
			if (temp!=last)
			{
				r[seg[0]]=i-1;
				f[seg[0]][0]=r[seg[0]]-l[seg[0]]+1;
				l[++seg[0]]=i;
				last=temp;
			}
			seg[i]=seg[0];
		}
		r[seg[0]]=n;
		f[seg[0]][0]=r[seg[0]]-l[seg[0]]+1;
		preDeal();
		while (m--)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			int na=seg[a],nb=seg[b],ans=max(min(b,r[na])-a+1,b-max(l[nb],a)+1);
			if (na<nb-1)
				ans=max(ans,rmq(na+1,nb-1));
			printf("%d\n",ans);
		}
	}
	return 0;
}
