#include <cstdio>
int n,a,k,sum;
int tick[10], mod[3][2];
int main(){
	scanf("%d",&n);
	mod[1][0] = mod[1][1] = mod[2][0] = mod[2][1] = 9;
	for (int i=1;i<=n;++i){
		scanf("%d",&a);
		sum += a;
		++tick[a];
		k=a%3;
		if (a < mod[k][0]){
			mod[k][1] = mod[k][0];
			mod[k][0] = a;
		}else if (a < mod[k][1]){
			mod[k][1] = a;
		}
	}
	if (!tick[0]){
		printf("-1\n");
	}else{
		int k = sum%3;
		if (k != 0){
			if (mod[k][0] != 9){
				--tick[mod[k][0]];
				--n;
			}else{
				--tick[mod[3-k][0]];
				--tick[mod[3-k][1]];
				n-=2;
			}
		}
		if (tick[0] == n){
			printf("0");
		}else{
			for (int i=9;i>=0;--i){
				while (tick[i]){
					--tick[i];
					printf("%d",i);
				}
			}
		}
	}
	printf("\n");
	return 0;
}
