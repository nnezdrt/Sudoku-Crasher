#include <stdio.h>
#define min(a,b) a>b?b:a
#define maxn 10001
#define maxm 50001
int list[maxn],head[maxn],next[maxm],v[maxm],g[maxn],all,n,m,a,b;
int vis[maxn],low[maxn],stack[maxn],s;
bool used[maxn];
void dfs(int now)
{
    used[now]=1;
    vis[now]=low[now]=++s;
    stack[++stack[0]]=now;
    for (int i=head[now];i;i=next[i])
    {
        int to=v[i];
        if (!vis[to])
            dfs(to),low[now]=min(low[now],low[to]);
        else if (used[to])
            low[now]=min(low[now],low[to]);
    }
    if (vis[now]==low[now])
    {
        ++g[0];
        do
        {
            int temp=stack[stack[0]];
            used[temp]=0;
            g[temp]=g[0];
        }while (stack[stack[0]--]!=now);
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    while (m--)
    {
        scanf("%d%d",&a,&b);
        v[++all]=b;
        next[all]=head[a];
        head[a]=all;
    }
    for (int i=1;i<=n;++i)
        if (!vis[i])
            dfs(i);
    bool out[maxn]={0};
    int ans=0,sum=0,k;
    for (int i=1;i<=n;++i)
        for (int j=head[i];j;j=next[j])
            if (g[i]!=g[v[j]])
            {
                out[g[i]]=1;
                break;
            }
    for (int i=1;i<=g[0];++i)
        if (!out[i])
        {
            ++sum;
            k=i;
        }
    if (sum==1)
        for (int i=1;i<=n;++i)
            if (g[i]==k)
                ++ans;
    printf("%d\n",ans);
    return 0;
}
