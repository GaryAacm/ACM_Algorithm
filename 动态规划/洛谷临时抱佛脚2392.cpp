#include<bits/stdc++.h>
using namespace std;
int s[4],num[100],k,ans,sum,dp[2501];
int main()
{
    for(int i=0;i<4;i++)
    {
        cin>>s[i];
    }
    for(int i=0;i<4;i++)
    {
        sum=0;
        for(int j=0;j<s[i];j++)
        {
            cin>>num[j];
            sum+=num[j];
        }//输入数据
        for(int j=0;j<s[i];j++)
        {
            for(k=sum/2;k>=num[j];k--)//不超过一半才符合要求，枚举不超过一半的子集
            {
                dp[k]=max(dp[k],dp[k-num[j]]+num[j]);//背包算法
            }
        }
        ans+=sum-dp[sum/2];//减去小的部分
        memset(dp,0,sizeof(dp));
    }
    cout<<ans;
    return 0;
}
