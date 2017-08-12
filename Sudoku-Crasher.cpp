#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
int map[10][10],ways=-1,ans[10][10];
bool rect[10][10],row[10][10],col[10][10];
string input;

int getRect(int row,int col)
{
	//get the rect number.
	return (row-1)/3*3+(col-1)/3+1;
}
void find(int now)
{
	/*
	*use dfs to find the answer
	*/
	if (now>81)
	{
		if (ways==-1)
		{
			int i,j;
			for (i=1;i<=9;++i)
			{
				for (j=1;j<=9;++j)
				{
					ans[i][j]=map[i][j];
				}
			}
		}
		++ways;
		return;
	}
	int nowrow=(now-1)/9+1,nowcol=(now-1)%9+1;
	if (map[nowrow][nowcol]) //the used block
	{
		find(now+1);
	}
	else
	{
		for (int k=1;k<=9;++k)
		{
			if (!rect[getRect(nowrow,nowcol)][k])
			{
				if (!row[nowrow][k])
				{
					if (!col[nowcol][k])
					{
						rect[getRect(nowrow,nowcol)][k]=1;
						row[nowrow][k]=1;
						col[nowcol][k]=1;
						map[nowrow][nowcol]=k;
						find(now+1);
						rect[getRect(nowrow,nowcol)][k]=0;
						row[nowrow][k]=0;
						col[nowcol][k]=0;
						map[nowrow][nowcol]=0;
					}
				}
			}
		}
	}
}
int main()
{
	cout << "enter the suduku map:(enter \"back\" to enter again)" << endl;
	for (int i=1;i<=9;++i)
	{
		cout << i << ':';
		cin >> input;
		if (input == "back")
		{
			i=i-2;
			continue;
		}
		for (int j=1;j<=9;++j)
		{
			map[i][j]=input[j-1]-'0';
			rect[getRect(i,j)][map[i][j]]=1;
			row[i][map[i][j]]=1;
			col[j][map[i][j]]=1;
		}
	}
	find(1);
	cout << "The answer is :" << endl;
	for (int i=1;i<=9;++i)
	{
		for (int j=1;j<=9;++j)
		{
			cout << ans[i][j] << ' ';
		}
		cout << endl;
	}
	cout << "And there is/are " << ways << " more way(s) to deal with the problem" << endl;
	system("pause");
	return 0;
}
