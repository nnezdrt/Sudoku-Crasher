#include <string>
#include <iostream>
using namespace std;
#define maxn 1000001
int prelen[maxn];
int main()
{
	int t;
	cin >> t;
	while (t--){
		string s;
		cin >> s;
		int n = s.length();
		s=" "+s;
		for (int i=2;i<=n;++i)
        {
            if (s[prelen[i-1]+1]==s[i])
                prelen[i]=prelen[i-1]+1;
            else
                prelen[i]=0;
        }
		int now = n;
		bool flag = false;
		while (now > n/3){
			now = prelen[now];
		}
		while (now){
			if (s.substr(now+1, n-2*now).find(s.substr(1, now)) != std::string::npos){
				break;
			}
			now = prelen[now];
		}
		cout << now << endl;
	}
	return 0;
}
