#include<bits/stdc++.h>
using namespace std;
const int maxn=10;
int n,x,y,val;
int value[maxn][maxn];
int dp[maxn][maxn][maxn][maxn];//表示的是到达两个点同时进行

int main()
{
    cin>>n;
    while(1)
    {
        cin>>x>>y>>val;
        if(x==0&&y==0&&val==0) break;
        value[x][y]=val;

    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=n;k++)
            {
                for(int l=1;l<=n;l++)
                {
                    dp[i][j][k][l]=max(max(dp[i-1][j][k-1][l],dp[i-1][j][k][l-1]),max(dp[i][j-1][k-1][l],dp[i][j-1][k][l-1]))
                    +value[i][j]+value[k][l];
                    if(i==k&&j==l) dp[i][j][k][l]-=value[i][j];//减去重复算的
                }
            }
        }
    }
    cout<<dp[n][n][n][n]<<endl;

    return 0;
}
