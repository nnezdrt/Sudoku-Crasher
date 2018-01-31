#include <stdio.h>
int t,n,m,next[10001];
char a[1000001],b[10001];
int main()
{
    scanf("%d",&t);
    getchar();
    while (t--)
    {
        int i,j,ch;
        n=m=0;
        while ((ch=getchar())!='\n')
            b[++m]=ch;
        while ((ch=getchar())!='\n')
            a[++n]=ch;
        i=1;j=0;
        while (i<=m)
            if (!j || b[i]==b[j])
                next[++i]=++j;
            else
                j=next[j];
        int ans=0;
        i=j=1;
        while (i<=n)
        {
            if (!j || a[i]==b[j])
            {
                ++i;
                ++j;
            }
            else
                j=next[j];
            if (j==m+1)
            {
                j=next[j];
                ++ans;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
