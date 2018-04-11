#include <stdio.h>
long long n,f[10001]={1};
main(){
	for (int i=1;i<=21;++i)
		for (int j=i*i*i;j<=10000;++j)
			f[j]+=f[j-i*i*i];
	while (~scanf("%lld",&n))
		printf("%lld\n",f[n]);
}
