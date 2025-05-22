#include<bits/stdc++.h>
using namespace std;
long long c[25][25];
int main()
{
    for(int i=0;i<=21;++i)
    {
        c[i][0]=c[i][i]=1;
        for(int j=1;j<i;j++)
        {
            c[i][j]=c[i-1][j-1]+c[i-1][j];//µÝÍÆ
        }
    }
    return 0;
}
