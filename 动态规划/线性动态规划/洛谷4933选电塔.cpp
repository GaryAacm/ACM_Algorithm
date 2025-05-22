/*从当前数，枚举前面的数和公差进行推导*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
const int mod=998244353;
int dp[maxn][40005];//以i结尾公差为j
int n;
int a[maxn];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int ans=0;
    int p=20000;
    for(int i=1;i<=n;i++)
    {
        ans++;//表示单独一个
        for(int j=i-1;j;j--)
        {
            dp[i][a[i]-a[j]+p]+=dp[j][a[i]-a[j]+p]+1;//由前面一个推到过来
            dp[i][a[i]-a[j]+p]%=mod;
            ans+=dp[j][a[i]-a[j]+p]+1;//表示由前面符合条件的推导来的，加上去
            ans%=mod;
        }
    }
    cout<<ans<<endl;
}
