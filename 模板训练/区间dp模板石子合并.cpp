#include<bits/stdc++.h>
using namespace std;
const int maxn=305;
int a[maxn],n,s[maxn][maxn],sum[maxn];
int dp[maxn][maxn];

signed main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum[i]+=sum[i-1]+a[i];
    }
    for(int len=1;len<=n;len++)//���䳤��
    {
        for(int i=1;i+len<=n;i++)//��˵�
        {
            int j=i+len;
            dp[i][j]=1e9;
            for(int k=i;k<j;k++)//�Ҷ˵�
            {
                dp[i][j]=min(dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1],dp[i][j]);
            }
        }
    }
    cout<<dp[1][n]<<endl;
    return 0;
}

//s(i,j)��ʾdp(i,j) ȡ������ֵʱ��Ӧ���±�k�����Ծ����ҵ����ŵķָ�㣬���ٷָ��ö������
/*#include<bits/stdc++.h>
using namespace std;
const int maxn=305;
int a[maxn],n,s[maxn][maxn],sum[maxn];
int dp[maxn][maxn];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum[i]+=sum[i-1]+a[i];
        s[i][i]=i;//��ʼ��
    }

    for(int len=1;len<=n;len++)
    {
        for(int i=1;i+len<=n;i++)
        {
            int j=i+len;
            dp[i][j]=1e9;
            for(int k=s[i][j-1];k<=s[i+1][j];k++)
            {
                if(dp[i][j]>dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1])
                {
                    dp[i][j]=dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1];
                    s[i][j]=k;//��¼���ŷָ��
                }
            }
        }
    }
    cout<<dp[1][n]<<endl;
    return 0;
}*/
