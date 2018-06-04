#include <stdio.h>
#include <math.h>
double d,h,b,L,a;
double fun(double a)
{
	double temp1=sqrt(a*a+d*d),temp2=d+temp1;
	temp2=log(temp2)*a*a;
	temp1*=d;
	return (temp1+temp2-a*a*log(a))/a;
}
int main()
{
	int n,T;
	scanf("%d",&T);
	for (int tt=1;tt<=T;++tt)
	{
		if (tt-1)
			printf("\n");
		scanf("%lf%lf%lf%lf",&d,&h,&b,&L);
		n=(int)(b/d);
		if (d*n!=b)
			++n;
		d=b/n;
		L/=n;
		d/=2;
		double l=0.00001,r=h,mid,a;
		while (r-l>=0.0001)
		{
			mid=(r+l)/2;
			if (fun(d*d/(2*mid))>L)
				r=mid;
			else
				l=mid;
		}
		a=(l+r)/2;
		printf("Case %d:\n%.2lf\n",tt,h-a);
	}
	return 0;
}
