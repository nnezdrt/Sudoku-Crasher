#include <cstdio>
const int maxn = 1000005;
char s[maxn];
int n,nex[maxn];
void getNext(){
	nex[0] = -1;
	nex[1] = 0;
	int i=1,j=2;
	while (j<=n){
		if (i==0 || s[i] == s[j]){
			nex[j++] = i++;
		}else{
			i = nex[i-1] + 1;
		}
	}
}
int main(){
	int t=0;
	while (scanf("%d",&n),n){
		printf("Test case #%d\n",++t);
		scanf("%s",s+1);
		getNext();
		for (int i=2;i<=n;++i){
			int k = i - nex[i];
			if (i%k==0 && k != i){
				printf("%d %d\n",i, i/k);
			}
		}
		printf("\n");
	}
	return 0;
}
