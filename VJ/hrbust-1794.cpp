#include <stdio.h>
#include <string.h>
#define maxn 132001
char s[7];
int t,n,a,b,k;
long long f[maxn];
void add(int now,int l,int r)
{
    while (1)
    {
        int mid=l+r>>1;
        f[now]+=b;
        now=now<<1;
        if (mid>=a)
            r=mid;
        else
        {
            now=now|1;
            l=mid+1;
        }
        if (l==r)
        {
            f[now]+=b;
            return;
        }
    }
}
long long query(int now,int l,int r)
{
    if (l>=a && r<=b)
        return f[now];
    long long ans=0;
    int mid=l+r>>1;
    if (mid>=a)
        ans+=query(now<<1,l,mid);
    if (mid<b)
        ans+=query(now<<1|1,mid+1,r);
    return ans;
}
int main()
{
    scanf("%d",&t);
    for (int i=1;i<=t;++i)
    {
        memset(f,0,sizeof(f));
        printf("Case %d:\n",i);
        scanf("%d",&n);
        for (a=1;a<=n;++a)
        {
            scanf("%d",&b);
            add(1,1,n);
        }
        while (scanf("%s",s))
        {
            if (s[0]=='E')
                break;
            scanf("%d%d",&a,&b);
            if (s[0]=='Q')
                printf("%lld\n",query(1,1,n));
            else
            {
                if (s[0]=='S')
                    b=-b;
                add(1,1,n);
            }
        }
    }
    return 0;
}
