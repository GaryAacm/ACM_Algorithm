#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int n,m;
int dp[maxn],a[maxn],q[maxn];

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int h=1,t=0,ans=2e9;
    for(int i=1;i<=n;i++)
    {
        while(h<=t&&q[h]<i-m) h++;
        while(h<=t&&dp[q[t]]>=dp[i-1]) t--;
        q[++t]=i-1;
        dp[i]=dp[q[h]]+a[i];
        if(i>n-m) ans=min(ans,dp[i]);
    }
    cout<<ans;
    return 0;
}
