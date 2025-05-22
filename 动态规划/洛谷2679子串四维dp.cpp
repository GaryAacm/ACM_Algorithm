#include<bits/stdc++.h>
using namespace std;
const int md=1000000007;

int n,m,k;
char a[1001],b[201];
int dp[2][201][201][2];//分别表示使用了A匹配了多少B，用了几个子串，有没有用前面的

int main()
{
    scanf("%d%d%d",&n,&m,&k);
    scanf("%s%s",a+1,b+1);
    dp[0][0][0][0]=1;//初始化
    dp[1][0][0][0]=1;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            for(int p=1;p<=k;p++)
            {
                if(a[i]==b[j])
                {
                    dp[i%2][j][p][0]=dp[(i-1)%2][j][p][0]%md+dp[(i-1)%2][j][p][1]%md;
                    dp[i%2][j][p][0]%=md;
                    dp[i%2][j][p][1]=(dp[(i-1)%2][j-1][p-1][0]%md+dp[(i-1)%2][j-1][p][1]%md)%md+dp[(i-1)%2][j-1][p-1][1]%md;//每一步都取模数，加起来再取模数
                    dp[i%2][j][p][1]%=md;
                }
                else//匹配不上，不用
                {
                    dp[i%2][j][p][0]=dp[(i-1)%2][j][p][0]+dp[(i-1)%2][j][p][1];
                    dp[i%2][j][p][0]%=md;
                    dp[i%2][j][p][1]=0;//不能用
                }
            }
        }
    }
    printf("%d",(dp[n%2][m][k][1]+dp[n%2][m][k][0])%md);

    return 0;
}
