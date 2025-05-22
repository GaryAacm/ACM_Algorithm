#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;

int n,x;
long long dp[maxn][maxn];

struct node
{
    int lose,win,use;
}a[maxn];

int main()
{
    cin>>n>>x;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].lose>>a[i].win>>a[i].use;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=x;j++)
        {
            if(j<a[i].use)
            {
                //打不过
                dp[i][j]=dp[i-1][j]+a[i].lose;//认输
            }
            else//看是输还是赢要好，输了就不用药
            {
                dp[i][j]=max(dp[i-1][j]+a[i].lose,dp[i-1][j-a[i].use]+a[i].win);
            }
        }
    }
    cout<<5*dp[n][x]<<endl;
    return 0;
}
