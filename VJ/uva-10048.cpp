#include <stdio.h>
#include <algorithm>
using namespace std;
#define maxn 101
int tick,n,m,q;
int main()
{
    while (scanf("%d%d%d",&n,&m,&q),n)
    {
        int map[maxn][maxn]={0},x,y,temp;
        if (tick)
            putchar('\n');
        printf("Case #%d\n",++tick);
        while (m--)
        {
            scanf("%d%d%d",&x,&y,&temp);
            map[x][y]=map[y][x]=temp;
        }
        for (int k=1;k<=n;++k)
                for (int i=1;i<=n;++i)
                    for (int j=1;j<=n;++j)
                        if (map[i][k] && map[k][j])
                        {
                            temp=max(map[i][k],map[k][j]);
                            if (map[i][j])
                                map[i][j]=min(map[i][j],temp);
                            else
                                map[i][j]=temp;
                        }
        while (q--)
        {
            scanf("%d%d",&x,&y);
            if (map[x][y])
                printf("%d\n",map[x][y]);
            else
                printf("no path\n");
        }
    }
    return 0;
}
