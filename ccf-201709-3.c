//思路是把数据处理成一排（n的用处）并且去掉空格和转义，之后递归处理
//注意处理空对象
#include <stdio.h>
#include <string.h>
struct node
{
	char key[101][101],val[101][101];
	int isString[101],num;
}t[101];
int n,m,s;
int makeObj(char *str,int now)
{
	int i=0,j=0;
	//key
	while (str[i]!='}')
	{
		j=i;
		while (str[j]!='\"')
		{
			if (str[j]=='}')
				return j;
			++j;
		}
		char *temp=&str[++j];
		while (str[j]!=':')
			++j;
		str[--j]='\0';
		strcpy(t[now].key[++t[now].num],temp);
		j+=2;
		if (str[j]=='{')
		{
			int tick=++s;
			j+=makeObj(str+j+1,tick);
			t[now].val[t[now].num][0]=(char)tick;
			while (str[j]!='}')
				++j;
			++j;
		}
		else // else if (str[j] == '\"')
		{
			temp=&str[++j];
			while (str[j]!=',')
				++j;
			str[--j]='\0';
			t[now].isString[t[now].num]=1;
			strcpy(t[now].val[t[now].num],temp);
		}
		while (str[j]!='\"')
		{
			++j;
			if (str[j]=='}')
				return j;
		}
		i=j;
	}
	return i;
}
void preDeal()
{
	char temp[8001]={0};
	int i=0;
	while (n)
	{
		++i;
		temp[i]=getchar();
		if (temp[i]=='\n')
		{
			--n;
			if (n==0)
			{
				temp[i]='\0';
				break;
			}
			else
				--i;
		}
		else if (temp[i]==' ')
			--i;
		else if (temp[i]=='\\')
			temp[i]=getchar();
		else if (temp[i]=='}')
		{
			temp[i]=',';
			temp[++i]='}';
		}
	}
	makeObj(temp+1,++s); //temp+1 no first {
}
void findObj(char *nows)
{
	int i=0,j,k,sum=0;
	char list[101][101]={0};
	for (i=0;nows[i]!='\0';++i)
		if (nows[i]=='.')
		{
			nows[i]='\0';
			strcpy(list[++sum],nows);
			nows+=i+1;
			i=0;
		}
	for (++sum,i=0;nows[i]!='\0' && nows[i]!='\n';++i)
		list[sum][i]=nows[i];
	int now=1;
	for (i=1;i<=sum;++i)
	{
		int last=now;
		for (j=1;j<=t[now].num;++j)
		{
			if (!strcmp(t[now].key[j],list[i]))
			{
				if (i==sum)
				{
					if (t[now].isString[j])
						printf("STRING %s\n",t[now].val[j]);
					else
						printf("OBJECT\n");
					return;
				}
				else
				{
					if (t[now].isString[j])
					{
						printf("NOTEXIST\n");
						return;
					}
					else
					{
						now=(int)t[now].val[j][0];
						break;
					}
				}
			}
		}
		if (now==last)
		{
			printf("NOTEXIST\n");
			return;
		}
	}
	printf("NOTEXIST\n");
}
int main()
{
	memset(t,0,sizeof(t));
	scanf("%d%d",&n,&m);
	getchar();
	preDeal();
	while (m--)
	{
		char temp[101]={0};
		fgets(temp,100,stdin);
		findObj(temp);
	}
	return 0;
}
