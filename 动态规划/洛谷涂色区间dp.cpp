#include<bits/stdc++.h>
using namespace std;

//����˼·���ڴ��޿�ʼһ���Ը�������
char s[60];
int dp[60][60];

int main()
{
    scanf("%s",s+1);
    memset(dp,0x7f,sizeof(dp));
    int n=strlen(s+1);
    for(int i=1;i<=n;i++)
        dp[i][i]=1;//��ʼ����Ϳ���Լ���һ��Ҫһ��

    for(int len=2;len<=n;len++)
    {
        for(int i=1;i+len-1<=n;i++)
        {
            int j=i+len-1;
            if(s[i]==s[j])
                dp[i][j]=min(dp[i+1][j],dp[i][j-1]);//��ʾ����һ���Ը��ǣ���Ϊÿ��ֻ��ÿ�����ڵ���С����
            else

            {
                for(int k=i;k<j;k++)//����һ���Ը��ǣ�ö�ٷָ��
                {
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
                }
            }
        }
    }
    cout<<dp[1][n]<<endl;
    return 0;
}
