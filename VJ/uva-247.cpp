#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <string>
#include <map>
using namespace std;
#define maxn 26
int n,m,all,tick;
map<string,int>q;
int main()
{
    while (scanf("%d%d",&n,&m),n)
    {
        getchar();
        all=0;
        q.clear();
        string name[maxn];
        int f[maxn][maxn]={0};
        for (int i=1;i<=m;++i)
        {
            string sa,sb;
            cin >> sa >> sb;
            if (q.find(sa)==q.end())
            {
                q.insert(make_pair(sa,++all));
                name[all]=sa;
            }
            if (q.find(sb)==q.end())
            {
                q.insert(make_pair(sb,++all));
                name[all]=sb;
            }
            int a=q[sa],b=q[sb];
            f[a][b]=1;
        }
        for (int k=1;k<=n;++k)
            for (int i=1;i<=n;++i)
                for (int j=1;j<=n;++j)
                    f[i][j]=f[i][j]|(f[i][k]&&f[k][j]);
        if (tick)
            printf("\n");
        printf("Calling circles for data set %d:\n",++tick);
        bool used[maxn]={0};
        for (int i=1;i<=n;++i)
        {
            if (used[i])
                continue;
            used[i]=1;
            printf("%s",name[i].c_str());
            for (int j=i+1;j<=n;++j)
                if (f[i][j] && f[j][i] &&!used[j])
                {
                    used[j]=1;
                    printf(", %s",name[j].c_str());
                }
            printf("\n");
        }
    }
    return 0;
}
