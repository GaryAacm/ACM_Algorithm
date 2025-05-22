#include<bits/stdc++.h>
using namespace std;
#define N 310
int a[N],sum[N],dp[N][N];//为第i堆到第j堆的额最小付代价
//分别表示输入的代价，前缀和以及dp
int s[N][N];
int n;
int main()
{

    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        sum[i]=a[i]+sum[i-1];
        //求前缀和,便于计算代价
        s[i][i]=i;

    }
    //开始dp
    for(int len=2;len<=n;len++)//枚举区间长度
    {
        for(int i=1;i+len-1<=n;i++)//枚举左端点
        {
            int j=i+len-1;//枚举右端点
            dp[i][j]=1e9;
            for(int k=i;k<j;k++)
            //枚举分隔区间的点
            {
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1]);
            }
            //平行四边形优化
            /*for(int k=s[i][j-1];k<=s[i+1][j];k++)
            {
                if(dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1]<dp[i][j])
                {
                    dp[i][j]=dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1];
                    s[i][j]=k;//记录最优分割点
                }
            }*/

        }
    }
    printf("%d",dp[1][n]);
    return 0;
}
