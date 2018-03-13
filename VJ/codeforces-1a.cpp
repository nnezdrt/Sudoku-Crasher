#include <stdio.h>
long long n,m,a,ans;
int main()
{
    scanf("%lld%lld%lld",&n,&m,&a);
    ans=((n-1)/a+1)*((m-1)/a+1);
    printf("%lld\n",ans);
    return 0;
}
