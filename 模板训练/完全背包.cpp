#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
int dp[maxn];
int v,n;
struct node
{
    int cost,val;
}a[maxn];
//״̬ת�Ʒ��̣�dp(i,j)=max(dp(i-1,j),dp(i,j-v)+w)����i�йض�����i-1
int main()
{
    cin>>v>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].cost>>a[i].val;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=v;j++)//�������Ż�dp
        {
            dp[j]=dp[j];
            if(j>=a[i].cost)
            {
                dp[j]=max(dp[j],dp[j-a[i].cost]+a[i].val);
            }
        }
    }
    cout<<dp[v];
    return 0;
}
