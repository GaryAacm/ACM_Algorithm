/*#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=50+10;

int dp[maxn][105],a[maxn];//这个数字最长的序列满足条件的最后一个是j
int t,n;

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    dp[1][a[1]]=dp[1][a[1]+1]=1;
    int ans=1;
    for(int i=2;i<=n;i++)
    {
       for(int j=1;j<i;j++)
       {
           dp[i][a[i]]=max(dp[i][a[i]],dp[j][a[i]-1]+1);
           dp[i][a[i]+1]=max(dp[i][a[i]+1],dp[j][a[i]]+1);
       }
       ans = max(ans, max(dp[i][a[i]], dp[i][a[i] + 1]));//在中途每次都更新
    }
    cout<<ans<<endl;
}

signed main()
{
    cin>>t;
    while(t--)
    {
        memset(dp,0,sizeof(dp));
        solve();
    }
    return 0;
}*/

#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e6+10;

int dp[maxn][2],a[maxn],mp[maxn];//就是到了i的时候，是否要加一,mp用来记录出现最后的最大值的数
int t,n;

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
       dp[i][0]=mp[a[i]-1]+1;//不加一，由以前的情况推导而来
       dp[i][1]=mp[a[i]]+1;//加一
       mp[a[i]]=max(mp[a[i]],dp[i][0]);
       mp[a[i]+1]=max(mp[a[i]+1],dp[i][1]);
       ans = max(ans, max(dp[i][0], dp[i][1]));//在中途每次都更新
    }
    cout<<ans<<endl;
}

signed main()
{
    cin>>t;
    while(t--)
    {
        memset(dp,0,sizeof(dp));
        memset(mp,0,sizeof(mp));
        solve();
    }
    return 0;
}
