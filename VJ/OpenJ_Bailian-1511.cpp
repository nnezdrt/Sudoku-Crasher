#include <queue>
#include <cstdio>
#include <cstdlib>
#define maxn 2000001
#define INF 0x7fffffff
using namespace std;
int t,n,m;
long long ans;
int dis[maxn];
int head[maxn], nex[maxn], v[maxn], w[maxn], sum;
void add(int a,int b,int c){
	nex[++sum]=head[a];head[a]=sum;v[sum]=b;w[sum]=c;
	nex[++sum]=head[b+n/2];head[b+n/2]=sum;v[sum]=a+n/2;w[sum]=c;
}
void dij(){
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > >q;
	q.push(make_pair(dis[1], 1));
	q.push(make_pair(dis[n/2+1], n/2+1));
	while (q.size()){
		int now = q.top().second;
		if (q.top().first != dis[now]){
			q.pop();
			continue;
		}
		q.pop();
		for (int i=head[now];i;i=nex[i]){
			int to = v[i];
			if (dis[to] > dis[now] + w[i]){
				dis[to] = dis[now] + w[i];
				q.push(make_pair(dis[to], to));
			}
		}
	}
	for (int i=1;i<=n;++i){
		ans += dis[i];
	}
}
int main(){
	scanf("%d",&t);
	while (t--){
		scanf("%d%d",&n,&m);
		ans = sum = 0;
		n+=n;
		for (int i=1;i<=n;++i){
			dis[i] = INF;
			head[i] = 0;
		}
		dis[1] = dis[n/2+1] = 0;
		int a,b,c;
		for (int i=1;i<=m;++i){
			scanf("%d%d%d",&a,&b,&c);
			add(a,b,c);
		}
		dij();
		printf("%lld\n",ans);
	}
	return 0;
}
