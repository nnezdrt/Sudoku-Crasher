#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int p,y;
bool judge(int x){
	int k = min(p, (int)sqrt(x));
	for (int i=3;i<=k;i+=2){
		if (x%i==0)return false;
	}
	return true;
}
int main(){
	bool flag = false;
	scanf("%d%d",&p,&y);
	if ((y&1)==0)--y;
	for (int i=y;i>p;i-=2){
		if (judge(i)){
			printf("%d\n",i);
			flag = true;
			break;
		}
	}
	if (!flag)printf("-1\n");
	return 0;
}
