#include <stdio.h>
int n,t,list[21]={0,1};
bool isprime[41]={0,0,1},used[21]={0,1};
void dfs(int now)
{
    if (now==n+1)
    {
        if (isprime[list[1]+list[n]])
        {
            for (int i=1;i<n;++i)
                printf("%d ",list[i]);
            printf("%d\n",list[n]);
        }
        return;
    }
    for (int i=2;i<=n;++i)
    {
        if (!used[i] && isprime[i+list[now-1]])
        {
            list[now]=i;
            used[i]=1;
            dfs(now+1);
            used[i]=0;
        }
    }
}
int main()
{
    for (int i=3;i<=40;i+=2){
        isprime[i]=1;
        for (int j=2;j<i;++j){
        	if (i%j==0){
        		isprime[i] = 0;
        		break;
        	}
        }
    }
    while (~scanf("%d",&n))
    {
        printf("Case %d:\n",++t);
        if ((n&1)==0)dfs(2);
        putchar('\n');
    }
    return 0;
}
