#include <stdio.h>
#include <string.h>
#define min(a,b) ((a)<(b)?(a):(b))
#define maxn 200001
#define maxm 2000001
struct node
{
	int v,next;
}t[maxm];
bool used[maxn];
int thead[maxn],head[maxn],v[maxm],next[maxm];
int all,ans,n,m,key,keydeep,stack[maxn],low[maxn],vis[maxn],g[maxn];
void tarjan(int now,int fa)
{
  int k=1;
  low[now]=vis[now]=++all;
  used[now]=stack[++stack[0]]=now;
  for (int i=head[now];i;i=next[i])
  {
    int to=v[i];
    if (fa==to && k)
    {
    	--k;
    	continue;
    }
    if (!vis[to])
    {
      tarjan(to,now);
      low[now]=min(low[now],low[to]);
      if (low[to]>vis[now])
      	++ans;
    }
    else if (used[to])
      low[now]=min(low[now],vis[to]);
  }
  if (low[now]==vis[now])
  {
    ++g[0];
    do
    {
      k=stack[stack[0]--];
      used[k]=0;
      g[k]=g[0];
    }while (k!=now);
  }
}
void dfs(int now,int deep)
{
	if (deep>keydeep)
	{
		key=now;
		keydeep=deep;
	}
	used[now]=1;
	for (int i=thead[now];i;i=t[i].next)
		if (!used[t[i].v])
			dfs(t[i].v,deep+1);
}
inline void build(int a,int b,int num)
{
	t[num].v=b;
	t[num].next=thead[a];
	thead[a]=num;
}
inline void add(int a,int b,int num)
{
  v[num]=b;
  next[num]=head[a];
  head[a]=num;
}
int main()
{
  while (scanf("%d%d",&n,&m),n)
  {
    all=ans=g[0]=key=keydeep=0;
    for (int i=1;i<=n;++i)
      used[i]=stack[i]=thead[i]=head[i]=low[i]=vis[i]=0;
    for (int i=1;i<=m;++i)
    {
      int x,y;
      scanf("%d%d",&x,&y);
      add(x,y,i);
      add(y,x,i+m);
    }
    tarjan(1,m=0);
    for (int i=1;i<=n;++i)
    	for (int j=head[i];j;j=next[j])
    		if (g[i]-g[v[j]])
    		{
    			build(g[i],g[v[j]],++m);
    			build(g[v[j]],g[i],++m);
    		}
    memset(used,0,sizeof(used));
    dfs(1,0);
    memset(used,0,sizeof(used));
    dfs(key,keydeep=0);
    printf("%d\n",ans-keydeep);
  }
  return 0;
}
