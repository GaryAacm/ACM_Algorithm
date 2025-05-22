#include<bits/stdc++.h>
using namespace std;

struct node
{
    int iq,eq;
}a[405];
int n;
int dp[800005];//表示总的智商为j时的情商最大.01背包变形，智商为总的代价

int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i].iq>>a[i].eq;
    }

    memset(dp,-0x3f,sizeof(dp));
    dp[400000]=0;//防止数组越界

    for(int i=1;i<=n;++i)
    {
        if(a[i].iq>=0)
        {
            for(int j=800000;j>=a[i].iq;j--)
            {
                dp[j]=max(dp[j],dp[j-a[i].iq]+a[i].eq);
            }
        }
        else//顺序枚举避免负数重复
        {
            for(int j=1;j<=800000+a[i].iq;j++)
            {
                dp[j]=max(dp[j],dp[j-a[i].iq]+a[i].eq);
            }
        }
    }
    int ans=0;
    for(int i=400000;i<=800000;i++)
    {
        if(dp[i]>=0)
            ans=max(ans,dp[i]+i-400000);
    }
    cout<<ans<<endl;
}
