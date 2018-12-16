#include <cstdio>
const int maxn = 300001;
int t,n,a[maxn];
int main(){
	scanf("%d",&t);
	while (t--){
		scanf("%d",&n);
		for (int i=0;i<n;++i){
			scanf("%d",&a[i]);
		}
		int i=0,j=1,k;
		while (i<n && j<n){
			k=0;
			while (a[(i+k)%n] == a[(j+k)%n] && k<n){
				++k;
			}
			if (k == n) break;
			int left = (i+k)%n, right = (j+k)%n;
			if (a[left] < a[right]){
				j = right + 1;
			}else{
				i = j;
				++j;
			}
		}
		printf("%d",a[i]);
		for (int k=(i+1)%n;k!=i;k=(k+1)%n){
			printf(" %d",a[k]);
		}
		printf("\n");
	}
	return 0;
}
