#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 50001, maxm = 351, inf = 0x7fffffff;
int n,x,y,t;
int map[maxm][maxm];
struct dir{
	dir(int xx=0,int yy=0,int tt=0){x=xx;y=yy;t=tt;}
	int x,y,t;
}d[4]={dir(1,0),dir(-1,0),dir(0,1),dir(0,-1)};
int bfs(){
	queue<dir>q;
	q.push(dir(0,0,0));
	bool used[maxm][maxm]={0};
	while (q.size()){
		int x=q.front().x,y=q.front().y,t=q.front().t;
		q.pop();
		if (used[x][y])continue;
		used[x][y] = 1;
		if (map[x][y] == inf){
			return t;
		}
		for (int i=0;i<4;++i){
			int nowx=x+d[i].x,nowy=y+d[i].y;
			if (nowx>=0 && nowy>=0){
				if (t+1 < map[nowx][nowy]){
					q.push(dir(nowx, nowy, t+1));
				}
			}
		}
	}
	return -1;
}
int main(){
	for (int i=0;i<maxm;++i)
		for (int j=0;j<maxm;++j){
			map[i][j] = inf;
		}
	scanf("%d",&n);
	for (int i=1;i<=n;++i){
		scanf("%d%d%d",&x,&y,&t);
		map[x][y] = min(map[x][y], t);
		for (int j=0;j<4;++j){
			int nowx=x+d[j].x,nowy=d[j].y+y;
			if (nowx>=0 && nowy>=0){
				map[nowx][nowy] = min(map[nowx][nowy], t);
			}
		}
	}
	printf("%d\n",bfs());
	return 0;
}
