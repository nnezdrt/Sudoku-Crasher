#include <stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define maxn 101
#define maxm 10001
bool used[maxn];
int head[maxn],v[maxm],next[maxm];
int n,m,all,stack[maxn],g[maxn],vis[maxn],low[maxn],in[maxn],out[maxn];
inline void add(int a,int b,int num)
{
    v[num]=b;
    next[num]=head[a];
    head[a]=num;
}
void dfs(int now)
{
    used[now]=vis[now]=low[now]=++all;
    stack[++stack[0]]=now;
    for (int i=head[now];i;i=next[i])
    {
        int to=v[i];
        if (!vis[to])
            dfs(to),low[now]=min(low[now],low[to]);
        else if (used[to])
            low[now]=min(low[now],vis[to]);
    }
    if (low[now]==vis[now])
    {
        ++g[0];
        while (1)
        {
            int temp=stack[stack[0]--];
            used[temp]=0;
            g[temp]=g[0];
            if (temp==now)
                break;
        }
    }
}
int main()
{
    while (~scanf("%d",&n))
    {
        m=all=in[0]=out[0]=stack[0]=g[0]=0;
        for (int i=1;i<=n;++i)
        {
            vis[i]=in[i]=out[i]=low[i]=head[i]=used[i]=g[i]=0;
            int temp;
            while (scanf("%d",&temp),temp)
                add(i,temp,++m);
        }
        for (int i=1;i<=n;++i)
            if (!vis[i])
                dfs(i);
        for (int i=1;i<=n;++i)
        {
            for (int j=head[i];j;j=next[j])
            {
                int to=v[j];
                if (g[to]!=g[i])
                {
                    ++in[g[to]];
                    ++out[g[i]];
                }
            }
        }
        for (int i=1;i<=g[0];++i)
        {
            if (!in[i])
                ++in[0];
            if (!out[i])
                ++out[0];
        }
        if (g[0]==1)
            printf("1\n0\n");
        else
            printf("%d\n%d\n",in[0],max(in[0],out[0]));
    }
    return 0;
}
