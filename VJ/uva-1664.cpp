#include <algorithm>
#include <stdio.h>
using namespace std;
#define maxn 200001
struct node
{
    int a,b;
    long long c;
    bool operator <(const node& x)const
    {return c>x.c;}
}t[maxn];
int n,m,num[maxn],fa[maxn];
long long sum[maxn];
int getfa(int x)
{return fa[x]==x?x:fa[x]=getfa(fa[x]);}
int main()
{
    while (~scanf("%d",&n))
    {
        long long ans=0;
        for (int i=1;i<n;++i)
        {
            fa[i]=i;
            sum[i]=0;
            num[i]=1;
            scanf("%d%d%lld",&t[i].a,&t[i].b,&t[i].c);
        }
        fa[n]=n;
        num[n]=1;
        sum[n]=0;
        std::sort(t+1,t+n);
        for (int i=1;i<n;++i)
        {
            int a=getfa(t[i].a),b=getfa(t[i].b);
            long long suma=sum[a]+t[i].c*num[b],sumb=sum[b]+t[i].c*num[a];
            if (suma<sumb)
            {
                fa[a]=b;
                num[b]+=num[a];
                sum[b]=sumb;
                ans=max(ans,sumb);
            }
            else
            {
                fa[b]=a;
                num[a]+=num[b];
                sum[a]=suma;
                ans=max(ans,suma);
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
