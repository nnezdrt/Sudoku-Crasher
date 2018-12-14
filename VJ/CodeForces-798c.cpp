#include <cstdio>
const int maxn = 100001;
int n,a[maxn];
int gcd(int a,int b){
	return b?gcd(b, a%b):a;
}
int main(){
	scanf("%d",&n);
	int k;
	scanf("%d",&k);
	a[1] = k;
	for (int i=2;i<=n;++i){
		scanf("%d",&a[i]);
		k = gcd(k, a[i]);
	}
	int ans=0;
	if (k == 1){
		for (int i=1;i<n;++i){
			if ((a[i]&1) && (a[i+1]&1)){
				a[i] = a[i+1] = 2;
				++ans;
				++i;
			}
		}
		for (int i=1;i<n;++i){
			if ((a[i]&1) || (a[i+1]&1)){
				ans +=2;
				a[i] = a[i+1] = 2;
			}
		}
	}
	printf("YES\n%d\n",ans);
	return 0;
}
 
