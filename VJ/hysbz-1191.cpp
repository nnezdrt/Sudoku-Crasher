#include <stdio.h>
#include <string.h>
#define maxn 1001
bool used[maxn];
int x,y,n,m,ans,match[maxn];
int head[maxn],next[2*maxn],to[2*maxn],all;
void add(int a,int b)
{
    to[++all]=b;
    next[all]=head[a];
    head[a]=all;
}
bool dfs(int now)
{
    for (int i=head[now];i;i=next[i])
    {
        if (used[to[i]])
            continue;
        used[to[i]]=1;
        if (!match[to[i]] || dfs(match[to[i]]))
        {
            match[to[i]]=now;
            return true;
        }
    }
    return false;
}
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;++i)
    {
        scanf("%d%d",&x,&y);
        add(i,x);
        add(i,y);
    }
    for (int i=1;i<=m;++i)
    {
        memset(used,0,sizeof(used));
        if (dfs(i))
            ++ans;
        else
            break;
    }
    printf("%d\n",ans);
    return 0;
}
