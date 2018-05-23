#include <stdio.h>
#define mod 1000000007
int n,m,t,ans,next[100001],dp[100001];
char a[100001],b[100001];
int KMP()
{
    int k=-1,i=1,j=1;
    while (i<=n && j<=m)
    {
    	if (!dp[i])
    		dp[i]=dp[i-1];
        if (a[i]==b[j])
        {
            ++i;
            ++j;
            if (j==m+1)
            {
            	dp[i-1]=(dp[i-1]+dp[i-1-m])%mod;
            	j=1;
            	i-=m-1;
            }
        }
        else if (j==1)
            ++i;
        else
            j=next[j-1]+1;
    }
    return k;
}
int main()
{
    scanf("%d",&t);
    getchar();
    dp[0]=1;
    for (int tt=1;tt<=t;++tt)
    {
    	ans=n=m=0;
    	int ch;
    	while ((ch=getchar())!='\n')
    	{
    		a[++n]=ch;
    		dp[n]=0;
    	}
    	while ((ch=getchar())!='\n')
    		b[++m]=ch;
        for (int i=2;i<=m;++i)
        {
            if (b[next[i-1]+1]==b[i])
                next[i]=next[i-1]+1;
            else
                next[i]=0;
        }
        KMP();
        printf("Case #%d: %d\n",tt,dp[n]);
    }
    return 0;
}
