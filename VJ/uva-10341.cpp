#include <algorithm>
#include <stdio.h>
#include <cmath>
using namespace std;
#define abs(x) ((x)<0?(-(x)):(x))
double p,q,r,s,t,u;
double f(double x)
{return (p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u);}
int main()
{
	while (~scanf("%lf%lf%lf%lf%lf%lf",&p,&q,&r,&s,&t,&u))
	{
		if (f(0)<0 || f(1)>0)
		{
			printf("No solution\n");
			continue;
		}
		double l=0.0,r=1.0,mid;
		while (abs(r-l)>=0.0000001)
		{
			mid=(l+r)/2;
			if (f(mid)>0)
				l=mid;
			else
				r=mid;
		}
		printf("%.4lf\n",(l+r)/2);
	}
	return 0;
}
