#include<bits/stdc++.h>
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

    for(int len=2;len<=n;len++)
    {
        for(int i=1;i+len-1<=n;i++)
        {
            int j=i+len-1;
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
}
