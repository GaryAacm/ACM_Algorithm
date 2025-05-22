#include<bits/stdc++.h>
using namespace std;
const int maxn=32;
int n,temp,Max,ans=0;
int dp[maxn];

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>temp;
        for(int c=0;c<=30;c++)//枚举二进制
        {
            if((1<<c)&temp) //找到有一位1相同，即可以判断不为0
            {
                Max=max(Max,dp[c]+1);//更新加一
            }
        }
        for(int c=0;c<=30;c++)
        {
            if((1<<c)&temp) dp[c]=max(Max,dp[c]);//继承上面确定的最大值

        }
        ans=max(Max,ans);
    }
    cout<<ans;
}
