#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn=2e5+10;

ll n;

ll solve(ll x)
{
    ll sum=0;
    while(x>0)
    {
        sum+=x%10;
        x/=10;
    }
    return sum;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n;
    ll ans=0;
    for(ll i=1;i<=n;++i)
    {
        if(i%solve(i)==0)
            ans++;
    }
    cout<<ans<<endl;

}
