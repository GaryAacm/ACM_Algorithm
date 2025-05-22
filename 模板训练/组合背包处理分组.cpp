#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;//组合背包一组有多个，但是只能选一次
int dp[maxn],group[maxn],real_pos[maxn][maxn];
int V,n,s,tmp,tot=0;
struct node
{
    int cost,val;
}a[maxn];

int main()
{
    cin>>V>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].cost>>a[i].val>>tmp;
        group[tmp]++;
        tot=max(tot,tmp);
        real_pos[tmp][group[tmp]]=i;//处理好分组
    }
    for(int i=1;i<=tot;i++)
    {
        for(int j=V;j>=0;j--)
        {
            for(int k=1;k<=group[i];k++)
            {
                if(j>=a[real_pos[i][k]].cost)
                    dp[j]=max(dp[j],dp[j-a[real_pos[i][k]].cost]+a[real_pos[i][k]].val);//每组选最大的
            }

        }
    }

    cout<<dp[V];
    return 0;
}
