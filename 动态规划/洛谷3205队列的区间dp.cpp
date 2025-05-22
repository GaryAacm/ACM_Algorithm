#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
int dp[maxn][maxn][2],a[maxn];
int n;
//本质上还是分割队列为小区间的操作
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        dp[i][i][0]=1;//初始化，默认从左边进去为1,只是初始化一边就行，因为最后要0和1相加

    }

    //倒推法求现在的理想队形是由原来的什么情况推出的

    for(int len=2;len<=n;len++)
    {
        for(int i=1;i+len-1<=n;i++)
        {
            int j=i+len-1;
            //从左边进去
            if(a[i]<a[i+1]) dp[i][j][0]+=dp[i+1][j][0];
            if(a[i]<a[j]) dp[i][j][0]+=dp[i+1][j][1];
            //从右边进去
            if(a[j]>a[j-1]) dp[i][j][1]+=dp[i][j-1][1];
            if(a[j]>a[i]) dp[i][j][1]+=dp[i][j-1][0];

            dp[i][j][0]%=19650827;
			dp[i][j][1]%=19650827;
        }
    }
    cout<<(dp[1][n][0]+dp[1][n][1])%19650827<<endl;

    return 0;
}
