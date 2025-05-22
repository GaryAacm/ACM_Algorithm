#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int n,m;
int dp[maxn],a[maxn],q[maxn];

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int h=1,t=0,ans=2e9;
    for(int i=1;i<=n;i++)
    {
        while(h<=t&&q[h]<i-m) h++;
        while(h<=t&&dp[q[t]]>=dp[i-1]) t--;
        q[++t]=i-1;
        dp[i]=dp[q[h]]+a[i];
        if(i>n-m) ans=min(ans,dp[i]);
    }
    cout<<ans;
    return 0;
}
const int maxn=2e5+10;
int n,l,r;
int dp[maxn],a[maxn],q[maxn];

int main()
{
    cin>>n>>l>>r;
    for(int i=0;i<=n;i++)
    {
        cin>>a[i];
    }
    memset(dp,-0x3f,sizeof(dp));
    dp[0]=0;
    //单调队列维护一个跳跃区间的最值
    int h=1,t=0,ans=-2e9;
    for(int i=l;i<=n;i++)//表示跳第一次
    {
        while(h<=t&&dp[q[t]]<=dp[i-l])//队尾小于新的数，删去就行
        {
            t--;
        }
        while(h<=t&&q[h]<i-r) h++;//除去队首不在区间内的数，移动窗口
        q[++t]=i-l;//推入第i-l个数据
        dp[i]=dp[q[h]]+a[i];
        if(i>n-r) ans=max(ans,dp[i]);
    }
    cout<<ans<<endl;
    return 0;
}

