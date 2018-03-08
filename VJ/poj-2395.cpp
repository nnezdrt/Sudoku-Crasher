#include <stdio.h>
#include <algorithm>
#define maxn 2001
#define maxm 10001
int n,m,i,ans,f[maxn];
struct node
{int a,b,c;}t[maxm];
bool cmp(node a,node b)
{return a.c<b.c;}
int getfa(int x)
{
    if (f[x]!=x)
        f[x]=getfa(f[x]);
    return f[x];
}
int main()
{
    scanf("%d%d",&n,&m);
    for (i=1;i<=m;++i)
        scanf("%d%d%d",&t[i].a,&t[i].b,&t[i].c);
    for (i=1;i<=n;++i)
        f[i]=i;
    std::sort(t+1,t+m+1,cmp);
    for (i=1;i<=m;++i)
    {
        int x=getfa(t[i].a),y=getfa(t[i].b);
        if (x!=y)
        {
            ans=t[i].c;
            f[x]=y;
        }
    }
    printf("%d\n",ans);
    return 0;
}
