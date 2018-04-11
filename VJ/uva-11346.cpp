#include <stdio.h>
#include <math.h>
double a,b,s,t;
int main()
{
	scanf("%lf",&t);
	while (t--)
	{
		scanf("%lf%lf%lf",&a,&b,&s);
		a*=b;
		if (s>=a)
			printf("0.000000");
		else if (s==0)
			printf("100.000000");
		else
			printf("%.6lf",(a-s+s*log(s/a))/a*100);
		printf("%c\n",'%');
	}
	return 0;
}
