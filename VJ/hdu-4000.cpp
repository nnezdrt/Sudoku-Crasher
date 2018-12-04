#include <stdio.h>
#include <cstring>
using namespace std;
const int maxn = 100001, mod = 100000007;
long long numOfReverse;
int n,t,a,c[maxn];
int lowbit(int x){
	return x&(-x);
}
void update(int pos){
	while (pos <= n){
		++c[pos];
		pos += lowbit(pos);
	}
}
int getSum(int pos){
	int ret = 0;
	while (pos){
		ret += c[pos];
		pos -= lowbit(pos);
	}
	return ret;
}
int main(){
	scanf("%d",&t);
	for (int tt=1;tt<=t;++tt){
		long long ans = 0;
		scanf("%d",&n);
		memset(c, 0, sizeof(c));
		for (int i=1;i<=n;++i){
			scanf("%d",&a);
			update(a);
			numOfReverse = getSum(n) - getSum(a);
			long long k = n - a - numOfReverse;
			ans += k * (k - 1) / 2;
			ans -=(i - 1 - numOfReverse) * k;
		}
		printf("Case #%d: %lld\n",tt,ans%mod);
	}
	return 0;
}
