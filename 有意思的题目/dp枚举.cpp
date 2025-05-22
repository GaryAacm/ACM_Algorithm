/*  https://codeforces.com/contest/1914/problem/D  */
#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn=1e5+10;

int t,n;
int dp[maxn][2][2][2];//第一维是天数，第二位是是是否滑雪，后面类似。。。

int main()
{
    cin.tie(0);
    cout.tie(0);
    //freopen("D:\\算法进阶\\codeforce\\div3_12_19\\in.txt","r",stdin);
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int w=0;w<=n;w++)
        {
            for(int i=0;i<=1;i++)
            {
                for(int j=0;j<=1;j++)
                {
                    for(int k=0;k<=1;k++)
                        dp[w][i][j][k]=0;
                }
            }
        }
        vector<int> a(n);
    vector<int> b(n);
    vector<int> c(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
        cin>>b[i];
    for(int i=0;i<n;i++)
        cin>>c[i];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=1;j++)
        {
            for(int k=0;k<=1;k++)
            {
                dp[i+1][1][j][k]=max(dp[i+1][1][j][k],dp[i][0][j][k]+a[i]);//表示加上滑雪的最值，后面的类似
            }
        }

        for(int j=0;j<=1;j++)
        {
            for(int k=0;k<=1;k++)
            {
                dp[i+1][j][1][k]=max(dp[i+1][j][1][k],dp[i][j][0][k]+b[i]);
            }
        }

        for(int j=0;j<=1;j++)
        {
            for(int k=0;k<=1;k++)
            {
                dp[i+1][j][k][1]=max(dp[i+1][j][k][1],dp[i][j][k][0]+c[i]);
            }
        }

        for(int j=0;j<=1;j++)
        {
            for(int k=0;k<=1;k++)
            {
                for(int w=0;w<=1;w++)
                    dp[i+1][j][k][w]=max(dp[i+1][j][k][w],dp[i][j][k][w]);//什么都不选的1最值
            }
        }

    }
    cout<<dp[n][1][1][1]<<endl;//枚举全部情况

  }
    return 0;

}
