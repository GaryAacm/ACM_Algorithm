#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn=2e5+10;
ll n;
ll a[maxn];
int sum=0;
void solve(ll n)
{
    while(n>0)
    {
        a[sum++]=n%2;
        n/=2;
    }
}

int main()
{
    cin>>n;
    solve(n);
    int ans=0;
    for(int i=0;i<sum;i++)
    {
        if(a[i]==0)
            ans++;
        if(a[i]==1)
            break;
    }
    cout<<ans<<endl;
}
