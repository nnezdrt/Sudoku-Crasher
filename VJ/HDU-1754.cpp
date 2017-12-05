//neater and faster than before
#include <cstdio>
#include <cstring>
#define max(a,b) ((a)>(b)?(a):(b))
int n,m,ql,qr;
int a[525001];
inline int getLimit()
{
    int s=1;
    while (s<n)
        s=s<<1;
    return s;
}
void change(int x,int val)
{
    int now=n+x-1;
    a[now]=val;
    while (now!=1)
    {
        now=now>>1;
        a[now]=max(a[now<<1],a[now<<1|1]);
    }
}
int ask(int now,int nowl,int nowr)
{
    if (nowl>=ql && nowr<=qr)
        return a[now];
    int mid=(nowl+nowr)>>1,l=0,r=0;
    if (ql<=mid)
        l=ask(now<<1,nowl,mid);
    if (qr>mid)
        r=ask(now<<1|1,mid+1,nowr);
    return max(l,r);
}
int main()
{
    while (~scanf("%d%d\n",&n,&m))
    {
        int tempn=n;
        n=getLimit();
        memset(a,0,sizeof(a));
        for (int i=1;i<=tempn;++i)
        {
            int temp;
            scanf("%d",&temp);
            change(i,temp);
        }
        getchar();
        while (m--)
        {
            char ch;
            scanf("%c%d%d",&ch,&ql,&qr);
            getchar();
            if (ch=='U')
                change(ql,qr);
            else
                printf("%d\n",ask(1,1,n));
        }
    }
    return 0;
}
