#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn=2000;

map<ll,ll> mapp;
ll n;
ll solve(ll x)
{
    if(x<2) return 0;
    if(mapp.find(x)!=mapp.end()) return mapp[x];//每次按照顺序加入，不等于最后的说明之前算过
    return mapp[x]=solve(x/2) + solve((x+1)/2)+x;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin>>n;
    cout<<solve(n);
}
