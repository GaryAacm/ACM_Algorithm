#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
int dp[maxn][maxn];
int tim,n;
struct node
{
    int cost,val;
}a[maxn];

int main()
{
    cin>>tim>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].cost>>a[i].val;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=tim;j++)
        {
            if(j<a[i].cost) dp[i][j]=dp[i-1][j];
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-a[i].cost]+a[i].val);
            }
        }
    }
    cout<<dp[n][tim]<<endl;
    return 0;
}
