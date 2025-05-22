#include<bits/stdc++.h>//01背包问题
using namespace std;

int n,m;
long long a[150],dp[150][150];//dp表示第i种花摆放了j盆

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=0;i<=n;i++)
       dp[i][0]=1;//初始化，什么都不放也是一种摆法
    for(int i=1;i<=n;i++)//枚举花的种数
    {
        for(int j=1;j<=m;j++)//枚举几盆花
        //递推公式如下：
         //dp[i][j] = dp[i-1][j] + dp[i-1][j-1] + … dp[i-1][j-ai]
         //指的是前面一种开始1，这周不放到全部都放
        {
            for(int k=j;k>=j-a[i];k--)//这种花放多少盆？我们用变量k来循环，k>=j-a[i]表示可以继续放
            {
                //若不足则一样摆放下去即可,因为k限制了摆放的数目
                    if(k>=0) {
                    dp[i][j]+=dp[i-1][k];
                    dp[i][j]%=1000007;
                }
                else
                    break;
            }
        }
    }
    cout<<dp[n][m]<<endl;
}
