#include <stdio.h>
#define REST_PEOPLE 6
#define REST_MONEY 40
#define TARGET_MONEY 16
#define max(a,b) ((a)>(b)?(a):(b))
double sum,chicken;
void dfs(int now,int rest,int sign)
{
    if (now==REST_PEOPLE)
    {
        ++sum;
        sign=max(rest-TARGET_MONEY,sign);
        if (sign<0)
            ++chicken;
        if (sign==0)
            chicken+=0.5;
        return;
    }
    for (int i=1;i<=rest+now-REST_PEOPLE;++i)
    {
        dfs(now+1,rest-i,max(i-TARGET_MONEY,sign));
    }
}
int main()
{
    dfs(1,REST_MONEY,-99999999);
    printf("All:%.0lf\nTarget:%.0lf\nRate:%lf\n",sum,chicken,chicken/sum);
    return 0;
}
