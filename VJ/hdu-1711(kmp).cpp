#include <stdio.h>
int n,m,a[1000001],b[10001],t;
int next[10001];
int KMP()
{
    int k=-1,i=1,j=1;
    while (i<=n && j<=m)
    {
        if (a[i]==b[j])
        {
            ++i;
            ++j;
        }
        else if (j==1)
            ++i;
        else
            j=next[j-1]+1;
    }
    if (j==m+1)
        k=i-m;
    return k;
}
int main()
{
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;++i)
            scanf("%d",&a[i]);
        for (int i=1;i<=m;++i)
            scanf("%d",&b[i]);
        for (int i=2;i<=m;++i)
        {
            if (b[next[i-1]+1]==b[i])
                next[i]=next[i-1]+1;
            else
                next[i]=0;
        }
        printf("%d\n",KMP());
    }
    return 0;
}
