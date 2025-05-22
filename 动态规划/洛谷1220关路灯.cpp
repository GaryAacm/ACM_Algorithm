#include<bits/stdc++.h>
using namespace std;
const int maxn=60;

int n,c;
int a[maxn],b[maxn],sum[maxn];
int dp[maxn][maxn][2];//表示的是i到j关了时消耗的功率，第三维表示站在区间哪一边

int main()
{
    cin>>n>>c;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
        sum[i]+=sum[i-1]+b[i];//求前缀和
    }
    memset(dp,127,sizeof(dp));
    dp[c][c][0]=dp[c][c][1]=0;//初始化已经关了，此时起点从这里开始

    for(int len=2;len<=n;len++)
    {
        for(int i=1;i+len-1<=n;i++)
        {
            int j=i+len-1;
            //开始规划
            dp[i][j][0]=min(dp[i+1][j][0]+(a[i+1]-a[i])*(sum[i]+sum[n]-sum[j]),dp[i+1][j][1]+(a[j]-a[i])*(sum[i]+sum[n]-sum[j]));
            //上面的第二个就是往回走
            dp[i][j][1]=min(dp[i][j-1][1]+(a[j]-a[j-1])*(sum[i-1]+sum[n]-sum[j-1]),dp[i][j-1][0]+(a[j]-a[i])*(sum[i-1]+sum[n]-sum[j-1]));

        }
    }
    int ans=min(dp[1][n][0],dp[1][n][1]);

    cout<<ans<<endl;
    return 0;
}
