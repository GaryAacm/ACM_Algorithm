#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn=1e3+10;

ll n,m,q;
ll a[maxn],b[maxn][maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>b[i][j];//第i年第j个人长的身高
        }
    }
    while(q--)
    {
        int x,y,z;
        cin>>x>>y>>z;
        if(x==0)
        {
            cout<<a[y]-a[z]<<endl;
        }
        else
        {
            ll k1=a[y],k2=a[z];
            for(int i=1;i<=x;i++)
            {
                k1+=b[i][y];
                k2+=b[i][z];
            }
            cout<<k1-k2<<endl;
        }
    }
}

