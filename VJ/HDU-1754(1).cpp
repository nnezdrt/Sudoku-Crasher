//I will implement a simplified version
#include <cmath>
#include <cstdio>
#include <cstring>
int a[530001],n,m,ql,qr,limit;
inline int getLimit()
{
    int x;
    double temp=log2(n);
    x=(int)temp;
    if (x!=temp)
        ++x;
    return x;
}
inline int max(int x,int y)
{
    if (x>=y)
        return x;
    return y;
}
inline void add(int now,int val)
{
    a[now]+=val;
    while (now!=1)
    {
        now=(now>>1);
        a[now]=max(a[now+now],a[now+now+1]);
    }
}
int ask(int now,int nowl,int nowr)
{
    if (nowl==nowr)
        return a[now];
    if (nowl>=ql && nowr<=qr)
        return a[now];
    int m=(nowl+nowr)/2,l=0,r=0;
    if (ql<=m)
        l=max(l,ask(now+now,nowl,m));
    if (qr>m)
        r=max(r,ask(now+now+1,m+1,nowr));
    return max(l,r);
}
int main()
{
    while (~scanf("%d%d\n",&n,&m))
    {
        limit=getLimit();
        limit=(1<<limit);
        memset(a,0,sizeof(a));
        for (int i=1;i<=n;++i)
        {
            int temp;
            scanf("%d",&temp);
            add(limit+i-1,temp);
        }
        getchar();
        while (m--)
        {
            char ch;
            scanf("%c%d%d",&ch,&ql,&qr);
            getchar();
            if (ch=='U')
                add(limit+ql-1,qr-a[limit+ql-1]);
            else
                printf("%d\n",ask(1,1,limit));
        }
    }
    return 0;
}
