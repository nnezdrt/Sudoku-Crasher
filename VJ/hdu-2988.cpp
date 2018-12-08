#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 200004;
struct edge{
	int u,v,w;
	bool operator <(const edge& x)const{
		return w<x.w;
	}
}e[maxn];
int n,m,fa[maxn];
int getfa(int x){
	return (x == fa[x])?x:fa[x]=getfa(fa[x]);
}
int kruskal(){
	sort(e+1,e+m+1);
	int ret = 0, tick = 0, now = 1;
	while (tick != n-1){
		int a = getfa(e[now].u), b = getfa(e[now].v);
		if (a != b){
			fa[a] = b;
			ret += e[now].w;
			++tick;
		}
		++now;
	}
	return ret;
}
int main(){
	while (scanf("%d%d",&n,&m),n){
		int sum = 0;
		for (int i=0;i<=n;++i){
			fa[i] = i;
		}
		for (int i=1;i<=m;++i){
			scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
			sum += e[i].w;
		}
		printf("%d\n",sum - kruskal());
	}
	return 0;
}
