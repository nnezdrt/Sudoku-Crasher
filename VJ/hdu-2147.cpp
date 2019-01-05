#include <cstdio>
int a,b;
int main(){
	while (scanf("%d%d",&a,&b),a+b){
		if ((a&1) && (b&1)){
			printf("What a pity!\n");
		}else{
			printf("Wonderful!\n");
		}
	}
	return 0;
}
