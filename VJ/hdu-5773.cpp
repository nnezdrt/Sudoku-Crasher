#include <stdio.h>
int n,T,f[100001]={-99999999};
int main()
{
	scanf("%d",&T);
	for (int tt=1;tt<=T;++tt)
	{
		int s=0,a,len=0;
		scanf("%d",&n);
		for (int i=1;i<=n;++i)
		{
			scanf("%d",&a);
			if (!a)
				++s;
			else
			{
				a-=s;
				if (f[len]<a)
					f[++len]=a;
				else
				{
					int l=1,r=len,mid;
					while (l<r)
					{
						mid=l+r>>1;
						if (f[mid]<=a)
							l=mid+1;
						else
							r=mid;
					}
					f[l]=a;
				}
			}
		}
		printf("Case #%d: %d\n",tt,len+s);
	}
	return 0;
}
