#include<bits/stdc++.h>//��ȫ��������
using namespace std;
const int maxn=1e7+10;
int tim,m;
struct node
{
    long long cost,val;
}a[maxn];
long long dp[maxn];

int main()
{
    cin>>tim>>m;
    for(int i=1;i<=m;i++)
        cin>>a[i].cost>>a[i].val;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=tim;j++)//��ȫ�������Ż�
        {
            if(j>=a[i].cost)
            {
                dp[j]=max(dp[j],dp[j-a[i].cost]+a[i].val);
                //˳������ȫ������������01����,��Ϊ������µĻ�����ڵ��ȸ�����״̬
                //˳��Ļ�ǰ��Ľڵ������i״̬�������i״̬���»��ظ�
            }
        }

    }
    cout<<dp[tim]<<endl;
    return 0;
}
