/*�ӵ�ǰ����ö��ǰ������͹�������Ƶ�*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
const int mod=998244353;
int dp[maxn][40005];//��i��β����Ϊj
int n;
int a[maxn];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int ans=0;
    int p=20000;
    for(int i=1;i<=n;i++)
    {
        ans++;//��ʾ����һ��
        for(int j=i-1;j;j--)
        {
            dp[i][a[i]-a[j]+p]+=dp[j][a[i]-a[j]+p]+1;//��ǰ��һ���Ƶ�����
            dp[i][a[i]-a[j]+p]%=mod;
            ans+=dp[j][a[i]-a[j]+p]+1;//��ʾ��ǰ������������Ƶ����ģ�����ȥ
            ans%=mod;
        }
    }
    cout<<ans<<endl;
}
