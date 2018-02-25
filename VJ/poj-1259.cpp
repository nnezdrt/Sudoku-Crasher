#include <stdio.h>
#include <algorithm>
using namespace std;
#define maxn 101
struct point
{
    int x,y;
}t[maxn],f[maxn];
int T,n;
int operator ^ (const point& a,const point& b)
{
    return a.x*b.y-a.y*b.x;
}
bool operator < (const point& a,const point& b)
{
    if (!(a^b))
        return a.x*a.x<b.x*b.x;
    return (a^b)>0;
}
point operator - (const point& a,const point& b)
{
    return (point){a.x-b.x,a.y-b.y};
}
int solve(int m)
{
    int d[maxn][maxn]={0},ret=0;
    for (int i=2;i<=m;++i)
    {
        int j=i-1;
        while (j && (f[j]^f[i])==0)
            --j;
        bool flag=(j==i-1);
        while (j)
        {
            int s=(f[j]^f[i]),k=j-1;
            while (k && ((f[j]-f[i])^(f[k]-f[j]))>0)
                --k;
            if (k)
                s+=d[j][k];
            if (flag)
                d[i][j]=s;
            ret=max(ret,s);
            j=k;
        }
        if (flag)
            for (int j=2;j<i;++j)
                d[i][j]=max(d[i][j],d[i][j-1]);
    }
    return ret;
}
int deal()
{
    int ret=0;
    for (int i=1;i<=n;++i)
    {
        int m=0;
        for (int j=1;j<=n;++j)
            if (t[i].y>t[j].y || (t[i].y==t[j].y && t[i].x>t[j].x))
                f[++m]=t[j]-t[i];
        sort(f+1,f+m+1);
        ret=max(ret,solve(m));
    }
    return ret;
}
int main()
{
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&n);
        for (int i=1;i<=n;++i)
            scanf("%d%d",&t[i].x,&t[i].y);
        int temp=deal();
        printf("%d.%d\n",temp/2,(temp&1)*5);
    }
    return 0;
}
