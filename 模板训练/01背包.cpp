#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
int dp[maxn];
int tim,n;
struct node
{
    int cost,val;
}a[maxn];

int main()
{
    cin>>tim>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].cost>>a[i].val;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=tim;j>=a[i].cost;j--)//基础的优化dp
        {
            dp[j]=max(dp[j],dp[j-a[i].cost]+a[i].val);
        }
    }
    cout<<dp[tim];
    return 0;
}
