#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
#define int long long
const int maxn=2e5+10;

int t,n;
int a[maxn];

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n;
        int maxx=0,minn=1e10;
        int maxx2=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        sort(a+1,a+1+n);
        ll ans=0;
        for(int i=3;i<=n;i++) ans=max(ans,2*a[i]-a[i-1]-a[1]);
        for(int i=1;i<n-1;i++) ans=max(ans,a[n]+a[i+1]-2*a[i]);
        cout<<ans<<endl;

    }
}
