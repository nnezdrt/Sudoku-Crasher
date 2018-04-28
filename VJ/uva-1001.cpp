#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <queue>
using namespace std;
#define maxn 105
#define maxm 12100
#define INF 0x7fffffff
struct node
{
    int x,y,z,r;
    node(int _x=0,int _y=0,int _z=0,int _r=0)
    {x=_x;y=_y;z=_z;r=_r;}
}t[maxn];
struct nodee
{
    int v;
    double w;
    nodee(double _w=0,int _v=0)
    {v=_v;w=_w;}
    bool operator <(const nodee& x)const
    {return w>x.w;}
};
int n,m,head[maxn],v[maxm],nex[maxm];
double w[maxm];
inline void add(int a,int b,double c)
{
    v[++m]=b;
    w[m]=c;
    nex[m]=head[a];
    head[a]=m;
}
double deal()
{
    priority_queue<nodee> q;
    double dis[maxn];
    bool used[maxn]={0};
    for (int i=1;i<=n;++i)
        dis[i]=INF;
    dis[1]=0;
    q.push(nodee(0,1));
    while (!q.empty())
    {
        nodee temp=q.top();
        q.pop();
        int now=temp.v;
        if (dis[now]!=temp.w)
            continue;
        used[now]=1;
        for (int i=head[now];i;i=nex[i])
        {
            int to=v[i];
            if (!used[to] && w[i]+dis[now]<dis[to])
            {
                dis[to]=dis[now]+w[i];
                q.push(nodee(dis[to],to));
            }
        }
    }
    return dis[n]*10;
}
int main()
{
    int tick=0;
    while (scanf("%d",&n) && n+1)
    {
        m=0;
        ++n;
        for (int i=2;i<=n;++i)
            scanf("%d%d%d%d",&t[i].x,&t[i].y,&t[i].z,&t[i].r);
        ++n;
        t[1].r=t[n].r=0;
        scanf("%d%d%d",&t[1].x,&t[1].y,&t[1].z);
        scanf("%d%d%d",&t[n].x,&t[n].y,&t[n].z);
        memset(head,0,sizeof(head));
        for (int i=1;i<=n;++i)
            for (int j=i+1;j<=n;++j)
            {
                double xx=t[i].x-t[j].x,yy=t[i].y-t[j].y,zz=t[i].z-t[j].z;
                double temp=sqrt((xx*xx+yy*yy+zz*zz))-t[i].r-t[j].r;
                temp=max(temp,0.0);
                add(i,j,temp);
                add(j,i,temp);
            }
        printf("Cheese %d: Travel time = %.0lf sec\n",++tick,deal());
    }
    return 0;
}
