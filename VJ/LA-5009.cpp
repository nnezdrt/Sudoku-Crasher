#include <algorithm>
#include <stdio.h>
using namespace std;
#define maxn 10001
#define INF 0x7fffffff
int n,m,t;
struct node
{
	double a,b,c;
}e[maxn];
double f(double x)
{
	double ret=-INF;
	for (int i=1;i<=n;++i)
		ret=max(ret,e[i].a*x*x+e[i].b*x+e[i].c);
	return ret;
}
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;++i)
			scanf("%lf%lf%lf",&e[i].a,&e[i].b,&e[i].c);
		double l=0.0,r=1000.0,mid,mmid;
		while (r-l>=0.00000001)
		{
			mid=(l+r)/2;
			mmid=(mid+r)/2;
			if (f(mid)<f(mmid))
				r=mmid;
			else
				l=mid;
		}
		printf("%.4lf\n",f((l+r)/2));
	}
	return 0;
}
