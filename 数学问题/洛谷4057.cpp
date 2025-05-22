#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a,b,c;
ll gcd(ll x,ll y)
{
    return y?gcd(y,x%y):x;
}

int main()
{
    cin>>a>>b>>c;
    ll ans;
    ans=gcd(a,b);
    ll k=(a*b)/ans;
    ans=gcd(k,c);

    cout<<k*c/ans<<endl;
}
