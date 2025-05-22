#include<bits/stdc++.h>
using namespace std;

int v,n;
int dp[300005];
int a[300005];
int main()
{
    cin>>v>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=v;j>=a[i];j--)
            dp[j]=max(dp[j],dp[j-a[i]]+a[i]);
    }
    cout<<v-dp[v]<<endl;
    return 0;
}
