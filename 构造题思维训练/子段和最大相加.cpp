#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+10;
const int mod=1e9+7;
//一个是复习最大字段和，另外一个是对大数据取余数的处理
int t,n,a[maxn],dp[maxn],k;

void init()
{
    memset(dp,0,sizeof(dp));
}

void solve()
{
    cin>>n>>k;
    int ans=0,sum=0,maxx=0;
    init();
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    sum=(sum%mod+mod)%mod;//加上mod保证正数
    for(int i=1;i<=n;i++)
    {
       dp[i]=max(a[i],dp[i-1]+a[i]);
       maxx=max(maxx,dp[i]);
    }
    maxx%=mod;
    int mul=1;
    if(maxx<=0) cout<<sum<<'\n';
    else
    {
        for(int i=1;i<=k;i++)
        {
            sum=(sum+mul*maxx%mod+mod)%mod;//每次相加改变，对可能溢出的数据取余数
            mul=mul*2%mod;
        }
        cout<<sum<<'\n';
    }

    return ;

}

signed main()
{
    ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
    cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}
