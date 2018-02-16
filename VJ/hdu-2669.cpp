#include <stdio.h>
typedef long long ll;
int exgcd(int a,int b,ll &x,ll &y)
{
    if (!b)
        return x=1,y=0,a;
    int r=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return r;
}
int main()
{
    ll x,y;
    int a,b;
    while (~scanf("%d%d",&a,&b))
    {
        int d=exgcd(a,b,x,y);
        x=(x+b)%b;
        if (1%d || x<0)
        {
            printf("sorry\n");
            continue;
        }
        printf("%lld %lld\n",x,(1-x*a)/b);
    }
    return 0;
}
