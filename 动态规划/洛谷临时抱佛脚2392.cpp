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
        }//��������
        for(int j=0;j<s[i];j++)
        {
            for(k=sum/2;k>=num[j];k--)//������һ��ŷ���Ҫ��ö�ٲ�����һ����Ӽ�
            {
                dp[k]=max(dp[k],dp[k-num[j]]+num[j]);//�����㷨
            }
        }
        ans+=sum-dp[sum/2];//��ȥС�Ĳ���
        memset(dp,0,sizeof(dp));
    }
    cout<<ans;
    return 0;
}
