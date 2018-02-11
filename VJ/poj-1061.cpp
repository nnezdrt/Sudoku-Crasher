#include <stdio.h>
#include <algorithm>
typedef long long LL;
LL exgcd(LL a,LL b,LL &x,LL &y)
{
    if (!b)
        return x=1,y=0,a;
    LL r=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return r;
}
int main()
{
    LL m,n,x,y,l,g,c;
    scanf("%lld%lld%lld%lld%lld",&x,&y,&m,&n,&l);
    c=x-y;
    l/=g=exgcd(n-m,l,x,y);
    if (m==n || c%g)
        printf("Impossible\n");
    else
        printf("%lld\n",(x*c/g%l+l)%l);
    return 0;
}
