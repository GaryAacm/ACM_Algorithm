#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;

bool check(ll x)
{
    bool flag=true;
    while(x>=1)
    {
        int a=x%10;
        if(a&1)
        {
            flag=false;
            break;
        }
        x=x/10;
    }
    if(flag) return true;
    else return false;

}

ll n;
int main()
{
    cin>>n;
    ll ans=0;
    ll x=0;
    while(1)
    {
        if(check(x))
        {
            ans++;
        }
        if(ans==n)
        {
            cout<<x<<endl;
            break;
        }
        x+=2;

    }
}
