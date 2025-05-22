#include <iostream>
#include <cstring>
#include<algorithm>
#include<queue>
using namespace std;
int a[1010][1010];
int dp[1011][1011];
int n;
int dfs(int i,int j)
{
    if(i==n)
        return a[n][j];//就是到达最后一层
    if(dp[i][j]>=0)
        return dp[i][j];//记忆化搜索

    return dp[i][j]=max(dfs(i+1,j),dfs(i+1,j+1))+a[i][j];

}

int main()
{
    memset(dp,-1,sizeof(dp));
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
            cin>>a[i][j];
    }
    cout<<dfs(1,1)<<endl;
    return 0;
}
