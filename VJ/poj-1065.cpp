#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 5001, inf = 0x7fffffff;
int n,tt;
struct node{
	int l,w;
	bool operator <(const node& x)const{
		return l==x.l?w<x.w:l<x.l;
	}
}t[maxn];
int main()
{
	scanf("%d",&tt);
	while (tt--){
		scanf("%d",&n);
		for (int i=1;i<=n;++i){
			scanf("%d%d",&t[i].l,&t[i].w);
		}
		sort(t+1,t+n+1);
		int f[maxn] = {inf},len = 0;
		for (int i=1;i<=n;++i){
			if (t[i].w < f[len]){
				f[++len] = t[i].w;
			}else{
				int l=1,r=len,mid;
				while (l<r){
					mid = (l+r)/2;
					if (f[mid] > t[i].w){
						l = mid+1;
					}else{
						r = mid;
					}
				}
				if (f[l] <= t[i].w){
					f[l] = t[i].w;
				}
			}
		}
		printf("%d\n",len);
	}
	return 0;
}
