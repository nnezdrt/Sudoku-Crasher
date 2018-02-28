#include <stdio.h>
#include <algorithm>
#define min(a,b) (a>b?b:a)
#define mod 100000
#define maxn 20001
#define maxm 200001
int head[maxn],next[maxm],v[maxm],all;
int low[maxn],vis[maxn],bridge[maxm],n,m,a,b,num;
bool cut[maxn],haveCut;
void dfs(int now,int fa)
{
    int son=0;
    vis[now]=low[now]=++num;
    for (int i=head[now];i;i=next[i])
    {
        int to=v[i];
        if (!vis[to])
        {
            ++son;
            dfs(to,now);
            low[now]=min(low[now],low[to]);
            if (vis[now]<low[to])
            {
                if (now<to)
                    bridge[++bridge[0]]=now*mod+to;
                else
                    bridge[++bridge[0]]=to*mod+now;
            }
            if (fa)
            {
                if (vis[now]<=low[to])
                    cut[now]=1;
            }
            else if (son>1)
                cut[now]=1;
        }
        else if (fa!=to)
            low[now]=min(vis[to],low[now]);
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;++i)
    {
        scanf("%d%d",&a,&b);
        v[i]=b;v[m+i]=a;
        next[i]=head[a];
        next[m+i]=head[b];
        head[a]=i;
        head[b]=m+i;
    }
    dfs(1,0);
    std::sort(bridge+1,bridge+bridge[0]+1);
    for (int i=1;i<=n;++i)
        if (cut[i])
        {
            printf("%d ",i);
            haveCut=1;
        }
    if (!haveCut)
        printf("Null");
    putchar('\n');
    for (int i=1;i<=bridge[0];++i)
        printf("%d %d\n",bridge[i]/mod,bridge[i]%mod);
    return 0;
}
