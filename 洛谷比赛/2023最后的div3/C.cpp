#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,t;

ll gcd(ll x,ll y)//求最大公因数
{
    return y? gcd(y,x%y):x;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n;
        ll ans=0;
        if(n%2==0)
        {
            ans^=gcd(n/2,n);
        }
        ans^=n;
        cout<<ans<<endl;
    }
}
