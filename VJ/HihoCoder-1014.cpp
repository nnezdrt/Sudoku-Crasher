#include <cstdio>
#include <cstring>
struct node
{
	int ans,ch[26];
}t[1000001];
char s[11];
int sum,n;
void build()
{
	int len=strlen(s),now=0,p=0;
	while (p<len)
	{
		int temp=s[p]-'a';
		if (!t[now].ch[temp])
			t[now].ch[temp]=++sum;
		++t[now].ans;
		now=t[now].ch[temp];
		++p;
	}
	++t[now].ans;
}
int ask()
{
	int len=strlen(s),now=0,p=0;
	while (p<len)
	{
		int temp=s[p]-'a';
		if (!t[now].ch[temp])
			return 0;
		now=t[now].ch[temp];
		++p;
	}
	return t[now].ans;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;++i)
	{
		memset(s,0,sizeof(s));
		scanf("%s",s);
		build();
	}
	scanf("%d",&n);
	for (int i=1;i<=n;++i)
	{
		memset(s,0,sizeof(s));
		scanf("%s",s);
		printf("%d\n",ask());
	}
	return 0;
}
