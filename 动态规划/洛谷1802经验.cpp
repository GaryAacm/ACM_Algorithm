#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;

int n,x;
long long dp[maxn][maxn];

struct node
{
    int lose,win,use;
}a[maxn];

int main()
{
    cin>>n>>x;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].lose>>a[i].win>>a[i].use;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=x;j++)
        {
            if(j<a[i].use)
            {
                //�򲻹�
                dp[i][j]=dp[i-1][j]+a[i].lose;//����
            }
            else//�����仹��ӮҪ�ã����˾Ͳ���ҩ
            {
                dp[i][j]=max(dp[i-1][j]+a[i].lose,dp[i-1][j-a[i].use]+a[i].win);
            }
        }
    }
    cout<<5*dp[n][x]<<endl;
    return 0;
}
