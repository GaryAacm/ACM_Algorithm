#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;//��ϱ���һ���ж��������ֻ��ѡһ��
int dp[maxn];
int V,n,s;
struct node
{
    int cost,val;
}a[maxn];

int main()
{
    cin>>n>>V;
    for(int i=1;i<=n;i++)
    {
        cin>>s;
        for(int j=1;j<=s;j++)
            cin>>a[i].cost>>a[i].val;
        for(int j=V;j>=1;j--)
        {
            for(int k=1;k<=s;k++)
            {
                if(j>=a[k].cost)
                    dp[j]=max(dp[j],dp[j-a[i].cost]+a[i].val);//ÿ��ѡ����
            }

        }
    }

    cout<<dp[V];
    return 0;
}
