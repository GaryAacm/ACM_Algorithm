#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+10;

int t,n;
int dp[maxn];
void init()
{
    for(int i=1;i<=60;i++)
    {
        dp[i]=maxn;
        if(i>=15) dp[i]=min(dp[i-15]+1,dp[i]);
        if(i>=10) dp[i]=min(dp[i-10]+1,dp[i]);
        if(i>=6) dp[i]=min(dp[i-6]+1,dp[i]);
        if(i>=3) dp[i]=min(dp[i-3]+1,dp[i]);
        if(i>=1) dp[i]=min(dp[i-1]+1,dp[i]);
    }
}

signed main()
{
    init();
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n<=60)
            cout<<dp[n]<<'\n';
        else
        {
            int sum=0;
            sum+=n/15;//一直用面额最大的15去凑
            n%=15;
            sum-=1;//往后退一个15，因为后面用到15的时候最大值会变化
            n+=15;
            sum+=dp[n];
            cout<<sum<<endl;
        }
    }
    return 0;
}
