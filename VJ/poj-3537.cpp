#include <cstdio>
#include <cmath>
const int maxn = 26;
int f[maxn]={0,6,12,22,30,32,44,54,64,76,86,98,110,118,130,132,162,170,184,194,202,282,290,302,356,1046};
int main(){
	int n;
	bool flag = false;
	while (~scanf("%d",&n)){
		for (int i=1;i<maxn;++i){
			if (f[i] == n){
				flag=true;
				printf("2\n");
				break;
			}
			if (f[i] > n){
				break;
			}
		}
		if (!flag){
			printf("1\n");
		}
	}
	return 0;
}
