#include<bits/stdc++.h>//01��������
using namespace std;

int n,m;
long long a[150],dp[150][150];//dp��ʾ��i�ֻ��ڷ���j��

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=0;i<=n;i++)
       dp[i][0]=1;//��ʼ����ʲô������Ҳ��һ�ְڷ�
    for(int i=1;i<=n;i++)//ö�ٻ�������
    {
        for(int j=1;j<=m;j++)//ö�ټ��軨
        //���ƹ�ʽ���£�
         //dp[i][j] = dp[i-1][j] + dp[i-1][j-1] + �� dp[i-1][j-ai]
         //ָ����ǰ��һ�ֿ�ʼ1�����ܲ��ŵ�ȫ������
        {
            for(int k=j;k>=j-a[i];k--)//���ֻ��Ŷ����裿�����ñ���k��ѭ����k>=j-a[i]��ʾ���Լ�����
            {
                //��������һ���ڷ���ȥ����,��Ϊk�����˰ڷŵ���Ŀ
                    if(k>=0) {
                    dp[i][j]+=dp[i-1][k];
                    dp[i][j]%=1000007;
                }
                else
                    break;
            }
        }
    }
    cout<<dp[n][m]<<endl;
}
