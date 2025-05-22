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
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        ans=a[1];
        for(int i=2;i<=n;i++)
        {
            if(ans>=a[i])
            {
                int k=ans/a[i]+1;
                a[i]*=k;
            }
            ans=a[i];
            //cout<<ans<<endl;
        }
        cout<<ans<<'\n';
    }
}
