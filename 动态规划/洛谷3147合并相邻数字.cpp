#include<bits/stdc++.h>
using namespace std;

int n,dp[61][270000];//��ʾ���Ǻϳɵ���Ϊi�����Ϊj����ʱ��Ҫ�����䳤��
int temp;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&temp);
        dp[temp][i]=1;//�漰����������󲻳����ϳ�58
    }
    int ans;
    for(int i=2;i<=58;++i)
    {
        for(int j=1;j<=n;++j)
        {
            if(!dp[i][j])
            {
                if(dp[i-1][j]&&dp[i-1][j+dp[i-1][j]])//�ܹ���������������
                {
                    dp[i][j]=dp[i-1][j]+dp[i-1][j+dp[i-1][j]];//������ǰ��ܹ��ϳ�i-1����������������кϲ�
                }
            }

            if(dp[i][j]) ans=i;
        }
    }
    printf("%d",ans);

    return 0;
}
