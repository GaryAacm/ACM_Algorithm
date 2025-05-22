#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+10;

int t,n,c[maxn],sum[maxn],vis[maxn];

//观察规则，大胆猜测
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];

    }
    sort(c+1,c+1+n);
    for(int i=1;i<=n;i++)
    {
        sum[i]=sum[i-1]+c[i];
    }
    if(c[1]!=1)
    {
        cout<<"NO"<<endl;
        return ;
    }
    bool f=true;
    for(int i=2;i<=n;i++)
    {
        if(sum[i-1]<c[i])
        {
            cout<<"NO"<<endl;
            return ;
        }
    }
    cout<<"YES"<<endl;
    return ;
}

signed main()
{
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
