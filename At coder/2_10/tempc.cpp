#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn=2000;

ll n,ans=0;

ll solve(ll x)
{
    if(x<2) return 0;
    ans+=x;
    if(x&1)
    {
        solve(x/2);
        solve(x/2+1);
        return ans;

    }
    else
    {
        solve(x/2);
        solve(x/2);
        return ans;
    }
    return ans;
}

int main()
{
    cin>>n;
    cout<<solve(n);
}
