#include<bits/stdc++.h>
using namespace std;

int n,t,a,b,c,m;
int group[1005],num[1005][1005];//num��ʾ��Ӧ�����ı��
int w[1005],val[1005];
int dp[1005];
int main()
{
    cin>>m>>n;
    int all=0;
    for(int i=1;i<=n;i++)
    {
        cin>>w[i]>>val[i]>>c;
        all=max(all,c);//���������
        group[c]++;//С��Ԫ�ؼ�һ
        num[c][group[c]]=i;
    }

    for(int i=1;i<=all;i++)//ö������
    {
        for(int j=m;j>=0;j--)//��ö����������Ϊ���治ͬ�鲻ͬ����
        {
            for(int k=1;k<=group[i];k++)//ö��С���Ԫ�أ�k�ǵڼ���Ԫ��
            {
                if(j>=w[num[i][k]])
                   dp[j]=max(dp[j],dp[j-w[num[i][k]]]+val[num[i][k]]);
            }
        }
    }

    cout<<dp[m]<<endl;

    return 0;
}
