#include<bits/stdc++.h>
using namespace std;
int n;
int high[10005];
int dp[1005];//��ʾ��i������β�������������
/*int LIS()
{
    memset(dp,0,sizeof(dp));
    int ans=1;
    dp[1]=1;//��һ����Ϊ1
    for(int i=2;i<=n;i++)
    {
        int maxx=0;
        for(int j=1;j<i;j++)//����ǰ�����
        {
            if(dp[j]>maxx&&high[j]<high[i])
            {
                maxx=dp[j];//�ҳ���ĸ���
            }
            dp[i]=maxx+1;//��С������£���Ȼ�ͼ����Լ���1
            if(dp[i]>ans) ans=dp[i];
        }
    }
    return ans;

}*/

int LIS()
{
    int d[10005];
    int len=1;
    d[1]=high[1];
    for(int i=2;i<=n;i++)
    {
        if(d[len]<high[i])
        {
            d[++len]=high[i];//���º����Ľڵ�
        }
        else
        {
            int j=lower_bound(d+1,d+1+len,high[i])-d;//�ҵ�d�����е�һ����high��ǰ��������滻������һ������
            d[j]=high[i];
        }
    }
    return len;
}

int main()
{
    while(cin>>n)
    {
        for(int i=1;i<=n;i++)
            cin>>high[i];
        cout<<LIS()<<endl;
    }
    return 0;
}


