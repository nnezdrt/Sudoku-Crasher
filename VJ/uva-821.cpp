#include <algorithm>
#include <stdio.h>
using namespace std;
int main()
{
    int a,b,n,t=0;
    while (scanf("%d%d",&a,&b),a)
    {
        ++t;
        n=max(a,b);
        int map[101][101]={0};
        map[a][b]=1;
        while (scanf("%d%d",&a,&b),a)
        {
            map[a][b]=1;
            n=max(max(a,b),n);
        }
        for (int k=1;k<=n;++k)
            for (int i=1;i<=n;++i)
                for (int j=1;j<=n;++j)
                    if (map[i][k] && map[k][j])
                    {
                        if (map[i][j])
                            map[i][j]=min(map[i][j],map[i][k]+map[k][j]);
                        else
                            map[i][j]=map[i][k]+map[k][j];
                    }
        double ans=0,tick=0;
        for (int i=1;i<=n;++i)
            for (int j=1;j<=n;++j)
                if (i-j && map[i][j])
                {
                    ans+=map[i][j];
                    ++tick;
                }
        printf("Case %d: average length between pages = %.3lf clicks\n",t,ans/tick);
    }
    return 0;
}
