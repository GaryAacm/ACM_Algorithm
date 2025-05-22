#include<bits/stdc++.h>
using namespace std;

int dp[405][405];
int n,a[205];

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i+n]=a[i];//化环状为链状
    }
    int maxnn=0;
    for(int len=2;len<=n+1;len++)
    {
        for(int i=1;i+len-1<=2*n;i++)
        {
            int j=i+len-1;
            for(int k=i+1;k<j;k++)
            {
                dp[i][j]=max(dp[i][j],dp[i][k]+dp[k][j]+a[i]*a[k]*a[j]);
            }

        }
    }
    for (int i=1;i<=n;i++) maxnn=max(maxnn,dp[i][n+i]);//环状找一段区间的最值
    cout<<maxnn;
    return 0;
}
