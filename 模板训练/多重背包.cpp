#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;//完全背包新增每件物品的个数限制
int dp[maxn],w[maxn],v[maxn];
int V,n;
int a,b,s,cnt=0;
/*struct node
{
    int cost,val,num;
}a[maxn];*/

/*int main()
{
    cin>>v>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].cost>>a[i].val>>a[i].num;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=v;j>=1;j--)
        {
            for(int k=0;k<=a[i].num&&k*a[i].cost<=j;k++)//增加价值的限制
                dp[j]=max(dp[j],dp[j-k*a[i].cost]+a[i].val*k);
        }
    }
    cout<<dp[v];
    return 0;
}*/

//下面是二进制优化
int main()
{
    cin>>V>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>b>>s;
        int k=1;
        while(k<=s)
        {
            w[++cnt]=k*a;
            v[cnt]=k*b;
            s-=k;
            k*=2;
        }
        if(s>0)
        {
            w[++cnt]=a*s;
            v[cnt]=b*s;
        }
    }
    for(int i=1;i<=cnt;i++)
    {
        for(int j=V;j>=w[i];j--)
        {
            dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
        }
    }
    cout<<dp[V];
    return 0;
}
