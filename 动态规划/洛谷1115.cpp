#include<bits/stdc++.h>
using namespace std;

const int maxn=2e5+10;
int n,a[maxn];
int dp[maxn];
int sum=-1e9;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        dp[i]=max(a[i],dp[i-1]+a[i]);//这里等于a[i]化解了连续的问题
        sum=max(sum,dp[i]);
    }
    cout<<sum;
    return 0;
}
