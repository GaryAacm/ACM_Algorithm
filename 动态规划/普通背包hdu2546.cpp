#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1005],dp[1005];
int main()
{
    while(cin>>n)
    {
        if(n==0) break;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        cin>>m;
        if(m<5)
        {
            cout<<m<<endl;
            continue;
        }
        if(n==1)
        {
            cout<<m-a[1]<<endl;
            continue;
        }
        sort(a+1,a+1+n);//������Ϊ���ҵ����ֵ��������������λ
        memset(dp,0,sizeof(dp));
        n--;//��ȥ������������ΪҪ����������ȥ����������
        //m-=5;
        for(int i=1;i<=n;i++)
        {
            for(int j=m-5;j>=a[i];j--)
            {
                dp[j]=min(dp[j],dp[j-a[i]]-a[i]);//�����㷨
            }
        }
        cout<<m+dp[m-5]-a[n+1]<<endl;
    }
    return 0;
}
