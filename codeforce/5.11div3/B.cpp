#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn=1005;
//Ë«Ö¸Õë
string a,b;
int n,m,t;
void solve()
{
    int ans=0;
    cin>>n>>m;
    cin>>a>>b;
    int p=0;
    for(int i=0;i<n;i++)
    {
        while(p<m&&b[p]!=a[i]) p++;
        if(p==m) break;
        ans++;
        p++;
    }
    cout<<ans<<endl;
}

signed main()
{
    cin>>t;
    while(t--)
    {
        solve();
    }
}
