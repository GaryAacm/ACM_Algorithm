#include<bits/stdc++.h>
using namespace std;

const int LEN=12;
int dp[LEN+1][10];//i表示有几位数，j表示开头的数字
int digit[LEN+1];//用来存储对于位置的数字

void init()
{
    dp[0][0]=1;
    for(int i=1;i<=LEN;i++)//数位长度
    {
        for(int j=0;j<10;j++)//开头的数字
        {
            for(int k=0;k<10;k++)//i-1位的开头数字
            {
                if(j!=4&&!(j==6&&k==2))//排除4开头和62开头的
                    dp[i][j]+=dp[i-1][k];
            }
        }
    }
}

int solve(int x)
{
    int len=0;
    while(x)
    {
        digit[++len]=x%10;
        x/=10;
    }
    int ans=0;int pre=-1;//记录前面的位数
    for(int i=len;i>=1;i--)//从高位开始
    {
        for(int j=0;j<digit[i];j++)//枚举对应位置的数字，从小到大
            {
                if(j!=4&&!(pre=6&&j==2))
                    ans+=dp[i][j];

            }
            if(digit[i]==4||(pre=6&&digit[i]==2))
            {
                ans--;
                break;
            }
            pre=digit[i];

    }
    return ans;
}

int main()
{
    int n,l;
    init();
    while(scanf("%d%d",&l,&n))
    {
        if(l==0&&n==0) break;
        printf("%d\n",solve(n)-solve(l-1));
    }


    return 0;
}
