#include <stdio.h>
#include <algorithm>
#define maxn 10001
#define maxm 100001
struct node{
	int a,b,next;
	bool operator <(const node& x)const
	{return a-x.a?a<x.a:b<x.b;}
}t[maxm],ans[maxm];
int head[maxn],low[maxn],vis[maxn],n,m,all,x,y,num,ansn;
inline void add(int a,int b,int num){
	t[num].a=a;t[num].b=b;
	t[num].next=head[a];head[a]=num;
}
void dfs(int now,int fa)
{
    vis[now]=low[now]=++all;
	for (int i=head[now];i;i=t[i].next){
		int to=t[i].b;
		if (!vis[to]){
			dfs(to,now);
			low[now]=std::min(low[now],low[to]);
			if (low[to]>vis[now]){
				ans[++ansn]=t[i];
				if (t[i].a>t[i].b){
				int temp=ans[ansn].a;
				ans[ansn].a=ans[ansn].b;
				ans[ansn].b=temp;
				}
			}
		}
		else if (fa-to)
			low[now]=std::min(low[now],vis[to]);
	}
}
int main()
{
	while (~scanf("%d",&n)){
		all=ansn=0;
		for (int i=1;i<=n;++i){
			head[i]=low[i]=vis[i]=0;
			scanf("%d (%d)",&x,&num);
			while (num--){
				scanf("%d",&y);
				add(x+1,y+1,++m);
				add(y+1,x+1,++m);
			}
		}
		for (int i=1;i<=n;++i)
			if (!vis[i])
				dfs(i,0);
		std::sort(ans+1,ans+ansn+1);
		printf("%d critical links\n",ansn);
		for (int i=1;i<=ansn;++i)
			printf("%d - %d\n",ans[i].a-1,ans[i].b-1);
		puts("");
	}
	return 0;
}
