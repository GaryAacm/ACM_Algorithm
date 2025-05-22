#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=1005;
double n,s;
double dp[maxn][maxn];//表示已经找到第i种位于第j个子系统里面的期望值，倒退求到
int main()
{
    scanf("%lf%lf",&n,&s);
    for(int i=n;i>=0;i--)
    {
        for(int j=s;j>=0;j--)
        {
            if(i==n&&j==s) dp[i][j]=0.0;
            else
            {
                //dp[i][j]=(i/n)*(j/s)*dp[i][j]+(1-i/n)*(j/s)*dp[i+1][j]+(i/n)*(1-j/s)*dp[i][j+1]+(1-i/n)*(1-j/s)*dp[i+1][j+1]+1;
                //dp[i][j]=(n*s+(n-i)*j*dp[i+1][j]+i*(s-j)*dp[i][j+1]+(n-i)*(s-j)*dp[i+1][j+1])/(n*s-i*j);
                dp[i][j]=((1-i/n)*(j/s)*dp[i+1][j]+(i/n)*(1-j/s)*dp[i][j+1]+(1-i/n)*(1-j/s)*dp[i+1][j+1]+1)/(1-(i/n)*(j/s));
            }
        }
    }
    printf("%.4lf",dp[0][0]);

    return 0;
}
