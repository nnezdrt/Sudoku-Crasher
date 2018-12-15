#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 100001;
int fa[maxn];
bool used[maxn];
int getfa(int x){
	return x==fa[x]?x:fa[x]=getfa(fa[x]);
}
int main(){
	int a,b,n,k;
	bool flag;
	while (1){
		n=0;
		flag = true;
		memset(used, 0, sizeof(used));
		for (int i=1;i<maxn;++i)
			fa[i] = i;
		while (scanf("%d%d",&a,&b),a){
			if (a==-1)break;
			used[a] = used[b] = 1;
			n=max(n,max(a,b));
			int x=getfa(a),y=getfa(b);
			if (x!=y){
				fa[x]=y;
			}else{
				flag=false;
			}
			k=a;
		}
		if (a==-1)break;
		k=getfa(k);
		for (int i=1;i<=n;++i){
			if (used[i]){
				if (getfa(i) != k){
					flag = false;
					break;
				}
			}
		}
		if (flag)printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
