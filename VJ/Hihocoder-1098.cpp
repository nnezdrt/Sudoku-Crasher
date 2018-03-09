#include <stdio.h>
#include <algorithm>
int fa[100001],n,m,i,ans;
struct node
{
    int a,b,c;
    bool operator <(const node& x)const
    {return c<x.c;}
}t[1000001];
int getfa(int x)
{return x-fa[x]?fa[x]=getfa(fa[x]):x;}
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;++i)
        scanf("%d%d%d",&t[i].a,&t[i].b,&t[i].c);
    for (int i=1;i<=n;++i)
        fa[i]=i;
    std::sort(t+1,t+m+1);
    for (int i=1;i<=m;++i)
    {
        int x=getfa(t[i].a),y=getfa(t[i].b);
        if (x!=y)
        {
            ans+=t[i].c;
            fa[x]=y;
        }
    }
    printf("%d\n",ans);
    return 0;
}
