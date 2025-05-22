#include<bits/stdc++.h>
using namespace std;

string s1,s2;
int dp[2001][2001];
int ans;

int main()
{
    cin>>s1>>s2;
    int n=s1.length();
    int m=s2.length();
    for(int i=1;i<=n;i++) dp[i][0]=i;//A变成B删除
    for(int i=1;i<=m;i++) dp[0][i]=i;//B变成A添加

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s1[i-1]==s2[j-1]) dp[i][j]=dp[i-1][j-1];
            else
            {
                dp[i][j]=min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;
            }
        }
    }
    cout<<dp[n][m]<<endl;
    return 0;
}
