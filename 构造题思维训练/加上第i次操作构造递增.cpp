#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn=2e5+10;

int t,n,a[maxn],ans[maxn],s[maxn];

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        s[i]=a[i]-a[i-1];//记录差值
        ans[i]=0;
    }
    for(int i=1;i<=n;i++)
    {
        if(s[i]>0) continue;//已经递增
        ans[a[i-1]]=i;
    }

    for(int i=1;i<=n;i++)
    {
        if(!ans[i]) ans[i]=1;//不影响单调性
    }
    for(int i=1;i<=n;i++)
    {
        cout<<ans[i]<<' ';
    }
    cout<<endl;

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}
