#include <stdio.h>
int n,m;
void output(int tick,char ch)
{
	if (tick==0)
		return;
	else if (tick==1)
		printf("%c",ch);
	else
		printf("%d%c",tick,ch);
}
int main()
{
	scanf("%d",&n);
	getchar();
	while (n--)
	{
		int tick=0;
		char last='\0',ch;
		while (ch=getchar())
		{
			if (ch=='\n')
			{
				output(tick,last);
				printf("\n");
				break;
			}
			if (ch==last)
				++tick;
			else
			{
				output(tick,last);
				tick=1;
				last=ch;
			}
		}
	}
	return 0;
}
