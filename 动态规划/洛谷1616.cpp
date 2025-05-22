#include<bits/stdc++.h>//完全背包问题
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
        for(int j=1;j<=tim;j++)//完全背包的优化
        {
            if(j>=a[i].cost)
            {
                dp[j]=max(dp[j],dp[j-a[i].cost]+a[i].val);
                //顺序是完全背包，逆序是01背包,因为逆序更新的话后面节点先更新至状态
                //顺序的话前面的节点更新至i状态后面的用i状态更新会重复
            }
        }

    }
    cout<<dp[tim]<<endl;
    return 0;
}
