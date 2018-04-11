#include <stdio.h>
int main()
{
	double car,cow,door;
	while (~scanf("%lf%lf%lf",&cow,&car,&door))
	{
		double s=car+cow;
		printf("%.5lf\n",(car*(s-1))/(s*(s-door-1)));
	}
	return 0;
}
