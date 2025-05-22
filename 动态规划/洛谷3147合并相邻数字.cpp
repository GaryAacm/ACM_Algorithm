#include<bits/stdc++.h>
using namespace std;

int n,dp[61][270000];//表示的是合成的数为i，起点为j，此时需要的区间长度
int temp;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&temp);
        dp[temp][i]=1;//涉及到倍增，最大不超过合成58
    }
    int ans;
    for(int i=2;i<=58;++i)
    {
        for(int j=1;j<=n;++j)
        {
            if(!dp[i][j])
            {
                if(dp[i-1][j]&&dp[i-1][j+dp[i-1][j]])//能够有两个相邻区间
                {
                    dp[i][j]=dp[i-1][j]+dp[i-1][j+dp[i-1][j]];//这里就是把能够合成i-1的两个相邻区间进行合并
                }
            }

            if(dp[i][j]) ans=i;
        }
    }
    printf("%d",ans);

    return 0;
}
