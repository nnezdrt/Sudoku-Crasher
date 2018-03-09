#include <stdio.h>
__int64 a[34]={1,3,11,41},b[34]={0,1,4,15},n,i;
int main()
{
    for (i=4;i<=33;++i)
    {
        a[i]+=a[i-1]*3+b[i-1]*2;
        b[i]+=a[i-1]+b[i-1];
    }
    while (scanf("%lld",&n) && ~n)
        printf("%lld, %lld\n",a[n],b[n]);
    return 0;
}
