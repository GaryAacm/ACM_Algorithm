#include<bits/stdc++.h>
using namespace std;
int dp[1005][1005];
string s;

int main()
{
    cin>>s;
    int m=s.length();

    for(int i=m-1;i>=0;i--)
    {
        for(int j=i+1;j<m;j++)
        {
            if(s[i]==s[j])
                dp[i][j]=dp[i+1][j-1];//��ʾ���ڲ���չ����Ҫ�ٽ��в���
            else
            {
                dp[i][j]=min(dp[i+1][j]+1,dp[i][j-1]+1);//�ڲ���һ�β���
            }
        }
    }
    cout<<dp[0][m-1]<<endl;
    return 0;
}
