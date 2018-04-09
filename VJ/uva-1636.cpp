#include <iostream>
#include <cstring>
using namespace std;
string s;
int main()
{
	while (cin >> s)
	{
		int n=s.length(),shotlive=0,shotsum=0,rolive=0;
		s=' '+s+s[0];
		for (int i=1;i<=n;++i)
			if (s[i]=='0')
			{
				++rolive;
				++shotsum;
				if (s[i+1]=='0')
					++shotlive;
			}
		if (shotlive*n==shotsum*rolive)
			cout << "EQUAL\n";
		else if (shotlive*n>shotsum*rolive)
			cout << "SHOOT\n";
		else
			cout << "ROTATE\n";
	}
	return 0;
}
