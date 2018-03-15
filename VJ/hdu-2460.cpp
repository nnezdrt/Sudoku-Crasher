#include <stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define maxn 100001
#define maxm 400001
bool isbr[maxn];
int head[maxn],v[maxm],next[maxm],bnum;
int t,n,m,q,all,ans,vis[maxn],low[maxn],fa[maxn];
inline void add(int a,int b,int num)
{
    isbr[num]=0;
    v[num]=b;
    next[num]=head[a];
    head[a]=num;
}
void dfs(int now)
{
    int i;
    bool flag=1;
    vis[now]=low[now]=++all;
    for (i=head[now];i;i=next[i])
    {
        int to=v[i];
        if (fa[now]==to && flag)
        {
            flag=0;
            continue;
        }
        if (!vis[to])
        {
            fa[to]=now;
            dfs(to);
            low[now]=min(low[now],low[to]);
            if (low[to]>vis[now])
            {
                isbr[to]=1;
                ++bnum;
            }
        }
        else if (vis[to]<vis[now])
            low[now]=min(low[now],vis[to]);
    }
}
void lca(int a,int b)
{
    if (vis[a]>vis[b])
        a^=b^=a^=b;
    while (vis[a]<vis[b])
    {
        if (isbr[b])
        {
            isbr[b]=0;
            --bnum;
        }
        b=fa[b];
    }
    while (vis[a]>vis[b])
    {
        if (isbr[a])
        {
            isbr[a]=0;
            --bnum;
        }
        a=fa[a];
    }
}
int main()
{
    while (scanf("%d%d",&n,&m),n)
    {
        int i;
        bnum=all=0;
        for (i=1;i<=n;++i)
        {
            head[i]=vis[i]=low[i]=isbr[i]=0;
            fa[i]=i;
        }
        for (i=1;i<=m;++i)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            add(a,b,i);
            add(b,a,i+m);
        }
        dfs(1);
        scanf("%d",&q);
        printf("Case %d:\n",++t);
        while (q--)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            lca(x,y);
            printf("%d\n",bnum);
        }
        putchar('\n');
    }
    return 0;
}
