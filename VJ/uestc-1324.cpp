#include <stdio.h>
#include <algorithm>
using namespace std;
#define maxn 262200
int n,m,k,a,b;
long long f[maxn];
void update(int now,int l,int r)
{
    if (l==r)
    {
        f[now]+=b;
        return;
    }
    int mid=l+r>>1;
    if (mid>=a)
        update(now<<1,l,mid);
    else
        update(now<<1|1,mid+1,r);
    f[now]=max(f[now<<1],f[now<<1|1]);
}
long long query(int now,int l,int r)
{
    if (l>=a && r<=b)
        return f[now];
    long long ans=0;
    int mid=l+r>>1;
    if (mid>=a)
        ans=max(ans,query(now<<1,l,mid));
    if (mid<b)
        ans=max(ans,query(now<<1|1,mid+1,r));
    return ans;
}
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;++i)
    {
        scanf("%d%d%d",&k,&a,&b);
        if (k==1)
            update(1,1,n);
        else
            printf("%lld\n",query(1,1,n));
    }
    return 0;
}
