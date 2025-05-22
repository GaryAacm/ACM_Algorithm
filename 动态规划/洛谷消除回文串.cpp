#include<bits/stdc++.h>
using namespace std;
const int maxn=510;
int a[maxn],dp[maxn][maxn];//表示合并区间的代价
int n;

int main()
{
    memset(dp,0x3f,sizeof(dp));
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        dp[i][i]=dp[i][i-1]=1;
    }

    for(int len=2;len<=n;len++)
    {
        for(int i=1;i+len-1<=n;i++)
        {
            int j=i+len-1;
            if(a[i]==a[j]) dp[i][j]=min(dp[i][j],dp[i+1][j-1]);
            for(int k=i;k<j;k++)
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);

        }
    }
    cout<<dp[1][n]<<endl;

    return 0;
}
