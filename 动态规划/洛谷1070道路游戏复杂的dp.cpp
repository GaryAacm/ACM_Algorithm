#include<bits/stdc++.h>
using namespace std;

int dp[1005],mp[1005][1005],n,m,p,cost[1005],ans,t;
int main()
{
    scanf("%d%d%d",&n,&m,&p);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            scanf("%d",&mp[i][j]);//��i���ߣ�jʱ��,��ά���鴦��ʱ������
        }
    }
    for(int i=1;i<=n;++i){//ÿ����Ļ���
        scanf("%d",&cost[i]);
    }
     for(int i=1;i<=m;++i){//��ʼ��
        dp[i] = -1e9;//�����п����и�����
    }

    for(int i=1;i<=m;i++)//ö��ʱ��
    {
        for(int j=1;j<=n;j++)//ö�ٵ���
        {
            ans=dp[i-1]-cost[j];//�������Ĵ���
            for(int k=0;k<p&&i+k<=m;k++)//����ȡ�Ⱥţ���Ȼ�߶�һ��,��0��ʼ��Ϊ�߱�·�Ľ��
            {
                t = j+k > n ? ((j+k)%n) : j+k;//����
                ans+=mp[t][i+k];
                dp[i+k]=max(dp[i+k],ans);

            }

        }
    }
    //���������������ԭ���������õ�һ���������ߣ������õ�һ���Ľ��������
    //�ٵ��ڶ����㣬�ڵڶ��������˻����˺󣬵ڶ����������ߣ��͵�һ�������˵ıȽϣ��õ���ֵ
    cout<<dp[m];

    return 0;
}
