#include<bits/stdc++.h>
using namespace std;
const int maxn=205;

int dp[maxn+1][maxn+1];
int n;

void part()//打表
{
    for(int i=1;i<=maxn;i++)
    {
        for(int j=1;j<=maxn;j++)
        {
            if(i==1&&j==1) dp[i][j]=1;
            else if(i<j) dp[i][j]=dp[i][i];
            else if(i==j) dp[i][j]=dp[i][j-1]+1;//加上自己一个
            else dp[i][j]=dp[i][j-1]+dp[i-j][j];
        }
    }
}
int main()
{
    part();
    while(scanf("%d",&n)!=EOF)
    {
        cout<<dp[n][n]<<endl;
    }

    return 0;
}
