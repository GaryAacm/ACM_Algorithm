#include<bits/stdc++.h>
using namespace std;
const int maxn=33333;

int m,n,mainwg[maxn],mainval[maxn],fuwg[maxn][3],fuval[maxn][3];
int dp[maxn],v,q,p;

int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>v>>p>>q;//�ϲ������͸���
        if(!q)//����
        {
            mainwg[i]=v;//��������
            mainval[i]=v*p;//������ֵ
        }
        else
        {
            //������
            fuwg[q][0]++;//�����ĸ�����Ŀ
            fuwg[q][fuwg[q][0]]=v;//�ڼ��������ļ�ֵ����
            fuval[q][fuwg[q][0]]=v*p;//��Ӧ�����¸����ļ�ֵ
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=n;j>=mainwg[i];j--)//���������Ż�
        {
            //ȡ�������
            dp[j]=max(dp[j],dp[j-mainwg[i]]+mainval[i]);

            //ȡ�����͸���1
            if(j>=mainwg[i]+fuwg[i][1]) dp[j]=max(dp[j],dp[j-mainwg[i]-fuwg[i][1]]+mainval[i]+fuval[i][1]);

            //�����͸���2
            if(j>=mainwg[i]+fuwg[i][2]) dp[j]=max(dp[j],dp[j-mainwg[i]-fuwg[i][2]]+mainval[i]+fuval[i][2]);

            //��������������
            if(j>=mainwg[i]+fuwg[i][1]+fuwg[i][2]) dp[j]=max(dp[j],dp[j-mainwg[i]-fuwg[i][1]-fuwg[i][2]]+mainval[i]+fuval[i][1]+fuval[i][2]);

        }
    }
    cout<<dp[n]<<endl;
    return 0;
}
