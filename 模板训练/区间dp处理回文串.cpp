#include<bits/stdc++.h>
using namespace std;
const int maxn=5010;
int a[maxn],n;
int dp1[maxn],dp2[maxn];
char s1[maxn],s2[maxn];
int dp[maxn][maxn];
//通过找到最长公共子序列，来找回文串

/*signed main()
{
    cin>>s1+1;
    n=strlen(s1+1);
    for(int i=1;i<=n;i++)
    {
        s2[i]=s1[n-i+1];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(s1[i]==s2[j])
            {
                dp1[j]=dp2[j-1]+1;
            }
            else
            {
                dp1[j]=max(dp1[j-1],dp2[j]);
            }

        }
        memcpy(dp2,dp1,sizeof(dp1));
    }
    cout<<n-dp1[n];
    return 0;
}*/

//直接dp方法求
signed main()
{
    cin>>s1;
    n=strlen(s1);
    for(int i=0;i<=n;i++) dp[i][i]=0;
    for(int i=n-1;i>=0;i--)
    {
        for(int j=i+1;j<n;j++)
        {
            if(s1[i]==s1[j])
            {
                dp[i][j]=dp[i+1][j-1];

            }
            else
            {
                dp[i][j]=min(dp[i+1][j],dp[i][j-1])+1;//从小区间扩展而来
            }
        }
    }
    cout<<dp[0][n-1]<<endl;
    return 0;
}
