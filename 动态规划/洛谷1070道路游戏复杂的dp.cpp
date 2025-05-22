#include<bits/stdc++.h>
using namespace std;

int dp[1005],mp[1005][1005],n,m,p,cost[1005],ans,t;
int main()
{
    scanf("%d%d%d",&n,&m,&p);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            scanf("%d",&mp[i][j]);//第i条边，j时刻,二维数组处理时间问题
        }
    }
    for(int i=1;i<=n;++i){//每个点的花费
        scanf("%d",&cost[i]);
    }
     for(int i=1;i<=m;++i){//初始化
        dp[i] = -1e9;//由于有可能有负数解
    }

    for(int i=1;i<=m;i++)//枚举时间
    {
        for(int j=1;j<=n;j++)//枚举点数
        {
            ans=dp[i-1]-cost[j];//到达这点的代价
            for(int k=0;k<p&&i+k<=m;k++)//不能取等号，不然走多一步,从0开始因为走本路的金币
            {
                t = j+k > n ? ((j+k)%n) : j+k;//处理环
                ans+=mp[t][i+k];
                dp[i+k]=max(dp[i+k],ans);

            }

        }
    }
    //上面可以这样处理，原因在于先让第一个机器人走，走完后得到一定的金币数量，
    //再到第二个点，在第二个点买了机器人后，第二个机器人走，和第一个机器人的比较，得到最值
    cout<<dp[m];

    return 0;
}
