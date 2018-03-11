#include <functional>
#include <string.h>
#include <stdio.h>
#include <queue>
#define maxn 1001
#define maxm 200001
using namespace std;
int to[maxm],w[maxm],v[maxm],nex[maxm];
int n,m,head[maxn],dis[maxn],cost[maxn];
inline void add(int a,int b,int c,int d,int num)
{
    to[num]=b;
    w[num]=c;
    v[num]=d;
    nex[num]=head[a];
    head[a]=num;
}
void dij()
{
    int x,y;
    scanf("%d%d",&x,&y);
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
    dis[x]=cost[x]=0;
    q.push(make_pair(0,x));
    while (!q.empty())
    {
        pair<int,int> temp=q.top();
        int now=temp.second;
        q.pop();
        if (dis[now]<temp.first)
            continue;
        for (int i=head[now];i;i=nex[i])
        {
            if (dis[to[i]]>dis[now]+w[i])
            {
                dis[to[i]]=dis[now]+w[i];
                cost[to[i]]=cost[now]+v[i];
                q.push(make_pair(dis[to[i]],to[i]));
            }
            else if (dis[to[i]]==dis[now]+w[i] && cost[to[i]]>cost[now]+v[i])
                cost[to[i]]=cost[now]+v[i];
        }
    }
    printf("%d %d\n",dis[y],cost[y]);
}
int main()
{
    while (scanf("%d%d",&n,&m),n)
    {
        for (int i=1;i<=n;++i)
        {
            dis[i]=cost[i]=0x7fffffff;
            head[i]=0;
        }
        for (int i=1;i<=m;++i)
        {
            int a,b,c,d;
            scanf("%d%d%d%d",&a,&b,&c,&d);
            add(a,b,c,d,i);
            add(b,a,c,d,i+m);
        }
        dij();
    }
    return 0;
}
