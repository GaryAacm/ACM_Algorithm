#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
ll n,a[maxn],q,sum[maxn];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum[i]+=sum[i-1]+a[i];
    }
    cin>>q;
    while(q--)
    {
        ll l,r;
        cin>>l>>r;
        cout<<sum[r]-sum[l-1]<<endl;
    }

    return 0;
}
