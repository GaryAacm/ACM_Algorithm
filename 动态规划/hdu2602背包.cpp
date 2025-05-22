#include<bits/stdc++.h>
using namespace std;
struct Bone
{
    int v,val;
}bone[1005];
int dp[1005];
int t,n,tot;

int ans()
{
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++)//枚举物品数量
    {
        for(int j=tot;j>=bone[i].v;j--)//枚举体积
        {
            dp[j]=max(dp[j],dp[j-bone[i].v]+bone[i].val);
        }
    }
    return dp[tot];
}

int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>tot;
        for(int i=1;i<=n;i++)
        {
            cin>>bone[i].val;
        }
        for(int i=1;i<=n;i++)
        {
            cin>>bone[i].v;
        }
        cout<<ans()<<endl;
    }
    return 0;
}
