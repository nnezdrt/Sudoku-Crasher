#include <stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define maxn 100001
int n,temp,hash[maxn]={0};
long long dp[maxn]={0};
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
    {
        scanf("%d",&temp);
        ++hash[temp];
    }
    dp[1]=hash[1];
    for (long long i=2;i<maxn;++i)
        dp[i]=max(dp[i-1],dp[i-2]+hash[i]*i);
    printf("%lld\n",dp[maxn-1]);
    return 0;
}
