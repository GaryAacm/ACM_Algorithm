#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn=2e5+10;

int T,n,m,a[1001][1001];
//利用1是质数俩进行处理，然后利用奇偶交替避免m是质数
//注意奇偶交接，所以交换奇偶部分
void solve()
{
    int tot=0;
    cin>>n>>m;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            a[i][j]=++tot;
        }
    }
    for(int i=1;i<=n/2;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cout<<a[i*2][j]<<' ';
        }
        cout<<'\n';
    }

    if(n&1)
    {
       for(int i=1;i<=n/2+1;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cout<<a[i*2-1][j]<<' ';
            }
            cout<<'\n';
        }
    }
    else
    {
       for(int i=1;i<=n/2;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cout<<a[i*2-1][j]<<' ';
            }
            cout<<'\n';
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>T;
    while(T--)
    {
        solve();
        cout<<'\n';
    }

    return 0;
}
