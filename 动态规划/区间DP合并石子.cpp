#include<bits/stdc++.h>
using namespace std;
#define N 310
int a[N],sum[N],dp[N][N];//Ϊ��i�ѵ���j�ѵĶ���С������
//�ֱ��ʾ����Ĵ��ۣ�ǰ׺���Լ�dp
int s[N][N];
int n;
int main()
{

    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        sum[i]=a[i]+sum[i-1];
        //��ǰ׺��,���ڼ������
        s[i][i]=i;

    }
    //��ʼdp
    for(int len=2;len<=n;len++)//ö�����䳤��
    {
        for(int i=1;i+len-1<=n;i++)//ö����˵�
        {
            int j=i+len-1;//ö���Ҷ˵�
            dp[i][j]=1e9;
            for(int k=i;k<j;k++)
            //ö�ٷָ�����ĵ�
            {
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1]);
            }
            //ƽ���ı����Ż�
            /*for(int k=s[i][j-1];k<=s[i+1][j];k++)
            {
                if(dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1]<dp[i][j])
                {
                    dp[i][j]=dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1];
                    s[i][j]=k;//��¼���ŷָ��
                }
            }*/

        }
    }
    printf("%d",dp[1][n]);
    return 0;
}
