#include <cstdio>
const int maxn=100001;
int bfs(int from, int to){
	bool used[maxn] = {0};
	int step[maxn], list[maxn], len = 0, now = 0;
	list[0] = from;
	step[from] = 0;
	used[from] = 1;
	while (now <= len){
		int temp = list[now++];
		if (temp+1 < maxn && !used[temp + 1]){
			used[temp+1] = 1;
			list[++len] = temp+1;
			step[temp+1] = step[temp] + 1;
		}
		if (temp-1 >= 0 && !used[temp - 1]){
			used[temp-1] = 1;
			list[++len] = temp-1;
			step[temp-1] = step[temp] + 1;
		}
		if (2*temp < maxn && !used[temp*2]){
			used[temp*2] = 1;
			list[++len] = temp*2;
			step[temp*2] = step[temp] + 1;
		}
		if (used[to]){
			break;
		}
	}
	return step[to];
}
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	if (n>=k){
		printf("%d\n",n-k);
	}else{
		printf("%d\n",bfs(n, k));
	}
	return 0;
}
