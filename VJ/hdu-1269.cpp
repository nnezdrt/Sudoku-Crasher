#include <stdio.h>
#include <string.h>
#define mem(x) memset(x,0,sizeof(x))
#define min(a,b) a>b?b:a
#define maxn 10001
#define maxm 100001
int n,m,a,b;
int head[maxn],v[maxm],next[maxm];
int vis[maxn],low[maxn],stack[maxn],g,num;
bool used[maxn];
void dfs(int now)
{
    vis[now]=low[now]=++num;
    used[now]=stack[++stack[0]]=now;
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
        int temp;
        ++g;
        do
        {
            temp=stack[stack[0]--];
            used[temp]=0;
        }
        while (temp!=now);
    }
}
int main()
{
    while (~scanf("%d%d",&n,&m),n)
    {
        stack[0]=num=g=0;
        mem(head);
        mem(used);
        mem(low);
        mem(vis);
        while (m)
        {
            scanf("%d%d",&a,&b);
            v[m]=b;
            next[m]=head[a];
            head[a]=m--;
        }
        for (int i=1;i<=n;++i)
            if (!vis[i])
                dfs(1);
        if (g-1)
            printf("No\n");
        else
            printf("Yes\n");
    }
    return 0;
}
