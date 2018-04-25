#include <algorithm>
#include <stdio.h>
using namespace std;
#define maxn 1001
#define maxm 500001
struct node
{
    int a,b,w;
    bool operator< (const node& x)const
    {return w<x.w;}
}t[maxm];
int n,m,q[9][maxn],T,fa[maxn],cost[9];
long long ans;
int getfa(int x)
{return x==fa[x]?x:fa[x]=getfa(fa[x]);}
inline long long deal(int tick)
{
    long long ret=0;
    for (int i=1;i<=m;++i)
    {
        if (tick==n-1)
            break;
        int a=getfa(t[i].a),b=getfa(t[i].b);
        if (a!=b)
        {
            fa[a]=b;
            ret+=t[i].w;
            ++tick;
        }
    }
    return ret;
}
int main()
{
    scanf("%d",&T);
    while (T--)
    {
        m=ans=0;
        int x[maxn],y[maxn];
        scanf("%d%d",&n,&q[0][0]);
        for (int i=1;i<=q[0][0];++i)
        {
            int temp;
            scanf("%d%d",&q[i][0],&cost[i]);
            for (int j=1;j<=q[i][0];++j)
                scanf("%d",&q[i][j]);
        }
        for (int i=1;i<=n;++i)
            scanf("%d%d",&x[i],&y[i]);
        for (int i=1;i<=n;++i)
        {
            fa[i]=i;
            for (int j=i+1;j<=n;++j)
            {
                t[++m].w=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
                t[m].a=i;
                t[m].b=j;
            }
        }
        sort(t+1,t+m+1);
        ans=deal(0);
        for (int i=1;i<(1<<q[0][0]);++i)
        {
            long long co=0;
            int tick=0;
            for (int j=1;j<=n;++j)
                fa[j]=j;
            for (int j=1;j<=q[0][0];++j)
                if (i&(1<<(j-1)))
                {
                    co+=cost[j];
                    int f=getfa(q[j][1]);
                    for (int k=2;k<=q[j][0];++k)
                    {
                        int temp=getfa(q[j][k]);
                        if (temp!=f)
                            ++tick;
                        fa[temp]=f;
                    }
                }
            long long temp=co+deal(tick);
            ans=min(ans,temp);
        }
        printf("%lld\n",ans);
        if (T)
            printf("\n");
    }
    return 0;
}
