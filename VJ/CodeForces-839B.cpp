#include <cstdio>
int seat2,seat4,m4,m2,m1,k;
int main(){
	scanf("%d%d",&seat4,&k);
	seat2 = seat4*2;
	int temp;
	for (int i=1;i<=k;++i){
		scanf("%d",&temp);
		m4 += temp/4;
		temp-=temp/4*4;
		m2 += temp/2;
		temp-=temp/2*2;
		m1 += temp;
	}
	seat4 -= m4;
	m4 = 0;
	if (seat4 < 0){
		m2 += (-seat4)*2;
		seat4 = 0;
	}
	seat2 -= m2;
	if (seat2 < 0){
		m2 = -seat2;
		if (seat4 == 0){
			printf("NO\n");
		}else{
			if (seat4 >= m2){
				if (seat4 * 2 - m2 >= m1){
					printf("YES\n");
				}else{
					printf("NO\n");
				}
			}else{
				m2 -= seat4;
				m1 += m2 * 2;
				if (seat4 >= m1){
					printf("YES\n");
				}else{
					printf("NO\n");
				}
			}
		}
	}else{
		seat2 += seat4 * 2;
		if (seat2 >= m1){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	return 0;
}
