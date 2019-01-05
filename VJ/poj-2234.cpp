#include <cstdio>
#include <cmath>
int n,a,b;
int main(){
	while (~scanf("%d",&n)){
		a=0;
		for (int i=1;i<=n;++i){
			scanf("%d",&b);
			a^=b;
		}
		if (a){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}
	return 0;
}
