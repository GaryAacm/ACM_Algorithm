#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e5+10;
//重要的思想，就是贪心处理不了局部问题的时候，要用dp来转移状态，dp意义就是处理贪心
int dp[maxn][2];//涉及到贪心不行的，用dp

int t,n,a[maxn];
string s;

bool cmp(int x,int y)
{
    return x>y;
}

void solve()
{
    cin>>n;
    cin>>s;
    s=" "+s;
    int ans=0,cnt=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        dp[i][0]=dp[i][1]=0;
    }
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='1')//有盖子
        {
            dp[i][0]=dp[i-1][0]+a[i-1];
            dp[i][1]=max(dp[i-1][0],dp[i-1][1])+a[i];
        }
        else dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
    }

    cout<<max(dp[n][0],dp[n][1])<<endl;
}

signed main()
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
