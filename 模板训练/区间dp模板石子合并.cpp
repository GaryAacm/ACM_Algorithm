#include<bits/stdc++.h>
using namespace std;
const int maxn=305;
int a[maxn],n,s[maxn][maxn],sum[maxn];
int dp[maxn][maxn];

signed main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum[i]+=sum[i-1]+a[i];
    }
    for(int len=1;len<=n;len++)//区间长度
    {
        for(int i=1;i+len<=n;i++)//左端点
        {
            int j=i+len;
            dp[i][j]=1e9;
            for(int k=i;k<j;k++)//右端点
            {
                dp[i][j]=min(dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1],dp[i][j]);
            }
        }
    }
    cout<<dp[1][n]<<endl;
    return 0;
}

//s(i,j)表示dp(i,j) 取得最优值时对应的下标k，所以就是找到最优的分割点，减少分割点枚举数量
/*#include<bits/stdc++.h>
using namespace std;
const int maxn=305;
int a[maxn],n,s[maxn][maxn],sum[maxn];
int dp[maxn][maxn];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum[i]+=sum[i-1]+a[i];
        s[i][i]=i;//初始化
    }

    for(int len=1;len<=n;len++)
    {
        for(int i=1;i+len<=n;i++)
        {
            int j=i+len;
            dp[i][j]=1e9;
            for(int k=s[i][j-1];k<=s[i+1][j];k++)
            {
                if(dp[i][j]>dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1])
                {
                    dp[i][j]=dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1];
                    s[i][j]=k;//记录最优分割点
                }
            }
        }
    }
    cout<<dp[1][n]<<endl;
    return 0;
}*/
