#include <cstdio>
int t;
unsigned long long l,r,ans;
int main(){
	scanf("%d",&t);
	while (t--){
		scanf("%lld%lld",&l,&r);
		ans = r;
		unsigned long long k = 1, b=l;
		while (k+k <= r){
			k+=k;
		}
		k/=2;
		while (k){
			if ((r&k)==0 && (b|k) < r){
				b |= k;
			}
			k/=2;
		}
		printf("%lld\n",ans|b);
	}
	return 0;
}
