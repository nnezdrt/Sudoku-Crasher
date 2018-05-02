#include <algorithm>
#include <stdio.h>
#include <map>
using namespace std;
#define maxn 100001
int n,T,q,f[maxn][31];
map<int,long long>g;
int gcd(int a,int b)
{return b?gcd(b,a%b):a;}
int rmq(int l,int r)
{
	int temp=r-l+1,k=0;
	while ((1<<k)<=temp)
		++k;
	--k;
	return gcd(f[l][k],f[r-(1<<k)+1][k]);
}
int main()
{
	scanf("%d",&T);
	for (int ss=1;ss<=T;++ss)
	{
		g.clear();
		printf("Case #%d:\n",ss);
		int temp,l,r;
		scanf("%d",&n);
		for (int i=1;i<=n;++i)
			scanf("%d",&f[i][0]);
		for (int k=1;(1<<k)<=n;++k)
			for (int i=1;i+(1<<k)-1<=n;++i)
				f[i][k]=gcd(f[i][k-1],f[i+(1<<(k-1))][k-1]);
		for (int i=1;i<=n;++i)
		{
			temp=f[i][0];
			int from=i;
			while (from<=n)
			{
				int l=from,r=n,mid;
				while (l<r)
				{
					mid=(l+r+1)/2;
					if (rmq(l,mid)==temp)
						l=mid;
					else
						r=mid-1;
				}
				if (g.find(temp)==g.end())
					g[temp]=0;
				g[temp]+=l-from+1;
				temp=rmq(i,from=l+1);
			}
		}
		scanf("%d",&q);
		while (q--)
		{
			scanf("%d%d",&l,&r);
			temp=rmq(l,r);
			printf("%d %lld\n",temp,g[temp]);
		}
	}
	return 0;
}
