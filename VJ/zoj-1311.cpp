#include <stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define maxn 101
#define maxm 20001
bool cut[maxn];
int head[maxn],v[maxm],next[maxm];
int n,m,all,ans,vis[maxn],low[maxn];
inline void add(int a,int b,int num)
{
    v[num]=b;
    next[num]=head[a];
    head[a]=num;
}
void dfs(int now,int fa)
{
    int son=0;
    vis[now]=low[now]=++all;
    for (int i=head[now];i;i=next[i])
    {
        int to=v[i];
        if (!vis[to])
        {
            ++son;
            dfs(to,now);
            low[now]=min(low[now],low[to]);
            if (low[to]>=vis[now])
                if (fa || son>1)
                    cut[now]=1;
        }
        else
            low[now]=min(low[now],vis[to]);
    }
}
int main()
{
    while (scanf("%d",&n),n)
    {
        ans=m=all=0;
        for (int i=1;i<=n;++i)
            head[i]=vis[i]=low[i]=cut[i]=0;
        int temp;
        while (1)
        {
            int first=1,a,b;
            while (scanf("%d",&b),b)
            {
                if (first)
                {
                    a=b;
                    first=0;
                }
                else
                {
                    add(a,b,++m);
                    add(b,a,++m);
                }
                int temp=getchar();
                if (temp=='\n')
                    break;
            }
            if (!b)
                break;
        }
        dfs(1,0);
        for (int i=1;i<=n;++i)
            if (cut[i])
                ++ans;
        printf("%d\n",ans);
    }
    return 0;
}
