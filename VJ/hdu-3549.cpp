#include <stdio.h>
#include <string.h>
#define min(a,b) ((a)>(b)?(b):(a))
#define INF 10000001
int map[16][16],n,m,t;
int bfs()
{
    int ans=0;
    while (1)
    {
        int list[16]={1,1},res[16]={0,INF},now=1,last[16]={0};
        while (now<=list[0])
        {
            for (int i=1;i<=n;++i)
            {
                if (res[i]==0 && map[list[now]][i]>0)
                {
                    res[i]=min(res[list[now]],map[list[now]][i]);
                    list[++list[0]]=i;
                    last[i]=list[now];
                }
            }
            ++now;
        }
        if (!res[n])
            return ans;
        for (int i=n;i!=1;i=last[i])
        {
            map[last[i]][i]-=res[n];
            map[i][last[i]]+=res[n];
        }
        ans+=res[n];
    }
    return ans;
}
int main()
{
    scanf("%d",&t);
    for (int k=1;k<=t;++k)
    {
        memset(map,0,sizeof(map));
        scanf("%d%d",&n,&m);
        for (int i=1;i<=m;++i)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            map[a][b]+=c;
        }
        printf("Case %d: %d\n",k,bfs());
    }
    return 0;
}
