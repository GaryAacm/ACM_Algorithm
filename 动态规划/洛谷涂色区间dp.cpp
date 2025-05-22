#include<bits/stdc++.h>
using namespace std;

//这题思路在于从无开始一次性覆盖问题
char s[60];
int dp[60][60];

int main()
{
    scanf("%s",s+1);
    memset(dp,0x7f,sizeof(dp));
    int n=strlen(s+1);
    for(int i=1;i<=n;i++)
        dp[i][i]=1;//初始化，涂上自己这一层要一次

    for(int len=2;len<=n;len++)
    {
        for(int i=1;i+len-1<=n;i++)
        {
            int j=i+len-1;
            if(s[i]==s[j])
                dp[i][j]=min(dp[i+1][j],dp[i][j-1]);//表示可以一次性覆盖，因为每次只是每次相邻的最小区间
            else

            {
                for(int k=i;k<j;k++)//不能一次性覆盖，枚举分割点
                {
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
                }
            }
        }
    }
    cout<<dp[1][n]<<endl;
    return 0;
}
