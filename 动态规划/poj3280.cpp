#include <iostream>
#include <cstring>
#include<algorithm>
using namespace std;

char s[2005],ch;
int n,m,x,y;
int w[30];
int dp[2005][2005];
int main()
{
    while(cin>>n>>m)
    {
        cin>>s;
        for(int i=0;i<n;i++)
        {
            cin>>ch>>x>>y;
            w[ch-'a']=min(x,y);//����ÿ���ַ��Ļ���
        }
        for(int i=m-1;i>=0;i--)
        {
            //ö������
            for(int j=i+1;j<m;j++)//ö�������յ�
            {
                if(s[i]==s[j])
                    dp[i][j]=dp[i+1][j-1];
                else
                {
                    dp[i][j]=min(dp[i+1][j]+w[s[i]-'a'],dp[i][j-1]+w[s[j]-'a']);
                }
            }
        }
        cout<<dp[0][m-1]<<endl;

    }
    return 0;
}
