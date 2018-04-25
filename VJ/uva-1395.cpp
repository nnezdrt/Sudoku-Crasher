#include <algorithm>
#include <stdio.h>
using namespace std;
#define INF 10001
#define maxn 101
#define maxm 5001
struct node
{
    int w,a,b;
    bool operator <(const node& x)const
    {return w<x.w;}
}t[maxm];
int n,m,fa[maxn];
int getfa(int x)
{return x==fa[x]?x:fa[x]=getfa(fa[x]);}
int deal(int from)
{
    int tick=0;
    for (int i=1;i<=n;++i)
        fa[i]=i;
    for (int i=from;i<=m;++i)
    {
        int a=getfa(t[i].a),b=getfa(t[i].b);
        if (a!=b)
        {
            fa[a]=b;
            ++tick;
            if (tick==n-1)
                return t[i].w-t[from].w;
        }
    }
    return INF;
}
int main()
{
    while (scanf("%d%d",&n,&m),n)
    {
        int ans=INF;
        for (int i=1;i<=m;++i)
            scanf("%d%d%d",&t[i].a,&t[i].b,&t[i].w);
        sort(t+1,t+m+1);
        for (int i=1;i<=m-n+2;++i)
            ans=min(ans,deal(i));
        printf("%d\n",ans==INF?-1:ans);
    }
    return 0;
}
