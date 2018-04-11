#include <stdio.h>
#include <math.h>
int ans[100001],n,m;
int main()
{
	while (~scanf("%d%d",&n,&m))
	{
		int num[31]={0},fac[31]={0};
		ans[0]=0;
		int temp=(int)sqrt(m);
		for (int i=2;i<=temp;++i)
		{
			if (!(m%i))
			{
				fac[++fac[0]]=i;
				while (m%i==0)
				{
					m/=i;
					++num[fac[0]];
				}
			}
		}
		if (m-1)
		{
			fac[++fac[0]]=m;
			++num[fac[0]];
		}
		for (int i=1;i<n;++i)
		{
			int a=n-i,b=i,tick=0;
			for (int j=1;j<=fac[0];++j)
			{
				while (a%fac[j]==0)
				{
					a/=fac[j];
					--num[j];
				}
				while(b%fac[j]==0)
				{
					b/=fac[j];
					++num[j];
				}
				if (num[j]<=0)
					++tick;
			}
			if (tick==fac[0])
				ans[++ans[0]]=i+1;
		}
		if (ans[0])
			printf("%d\n%d",ans[0],ans[1]);
		else
		{
			printf("0\n\n");
			continue;
		}
		for (int i=2;i<=ans[0];++i)
			printf(" %d",ans[i]);
		printf("\n");
	}
	return 0;
}
