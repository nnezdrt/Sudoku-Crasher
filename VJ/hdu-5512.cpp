#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;
int gcd(int a,int b){
	if (b){
		return gcd(b, a%b);
	}return a;
}
int main()
{
	int t,n,a,b;
	scanf("%d",&t);
	for (int i=1;i<=t;++i){
		scanf("%d%d%d",&n,&a,&b);
		int k = gcd(a,b);
		printf("Case #%d: ", i);
		if ((n/k)&1){
			printf("Yuwgna\n");
		}else{
			printf("Iaka\n");
		}
	}
	return 0;
}
