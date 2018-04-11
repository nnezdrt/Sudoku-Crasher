#include <stdio.h>
main(){
	int n,i,f[31]={1,2,4};
	for (i=3;i<=30;++i)
		f[i]=f[i-1]+f[i-2]+f[i-3];
	while (scanf("%d",&n),n)
		printf("%d\n",(1<<n)-f[n]);
}
