#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;
const int maxn=500005;
priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > >q;
int last[maxn],nex[maxn],n,k;
long long ans,a[maxn];
bool used[maxn];
int main(){
	scanf("%d%d",&k,&n);
	for (int i=1;i<=n;++i){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	--n;
	for (int i=1;i<=n;++i){
		a[i] = a[i+1] - a[i];
		last[i] = i - 1;
		nex[i] = i + 1;
		q.push(make_pair(a[i], i));
	}
	a[0] = a[n+1] = 0x7fffffff;
	nex[0] = 1;
	last[n+1] = n;
	while (k--){
		while (used[q.top().second])
			q.pop();
		int now = q.top().second;
		long long temp = q.top().first;
		ans += temp;
		q.pop();
		temp = a[now] = a[last[now]] + a[nex[now]] - temp;
		used[last[now]] = used[nex[now]] = 1;
		last[now] = last[last[now]];
		nex[last[now]] = now;
		nex[now] = nex[nex[now]];
		last[nex[now]] = now;
		q.push(make_pair(temp, now));
	}
	printf("%lld\n",ans);
	return 0;
}
