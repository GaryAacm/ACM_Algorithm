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
        for(int c=0;c<=30;c++)//ö�ٶ�����
        {
            if((1<<c)&temp) //�ҵ���һλ1��ͬ���������жϲ�Ϊ0
            {
                Max=max(Max,dp[c]+1);//���¼�һ
            }
        }
        for(int c=0;c<=30;c++)
        {
            if((1<<c)&temp) dp[c]=max(Max,dp[c]);//�̳�����ȷ�������ֵ

        }
        ans=max(Max,ans);
    }
    cout<<ans;
}
