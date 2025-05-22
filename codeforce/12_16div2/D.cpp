#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+10;
typedef long long  ll;
int t,n,m;
int source[maxn],a[maxn*2];
int dp[maxn*2];
bool vis[maxn];
int main()
{
     ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    //freopen("D:\\算法进阶\\codeforce\\12_16div2\\input.txt","r",stdin);
    cin>>t;
    while(t--)
    {
        cin>>n;
        memset(a,0,sizeof(a));
        memset(dp,0,sizeof(dp));

        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
            a[i+n]=a[i];
        }
        int minn=0,ans=0;
        for(int i=1;i<=2*n;++i)
        {
            minn=0;
            int maxx=1;
            int mixx=0;
            int j;
            for(int i=0;i<=n;++i) vis[i]=true;
            vis[minn]=false;

            for(j=i;j<i+n;++j)
            {
                if(minn!=a[j])
                  {
                      if(j==i)
                        dp[j]=minn;
                      else dp[j]=dp[j-1]+minn;
                      vis[minn]=false;
                      vis[a[j]]=false;


                  }
                else
                {

                    while(!vis[minn]) minn++;

                    if(j==i)
                        dp[j]=minn;
                      else dp[j]=dp[j-1]+minn;
                      vis[minn]=false;

                    //cout<<"j = "<<j<<" dp[j]= "<<dp[j]<<endl;
                }
            }
            //cout<<"调用"<<"j = "<<j<<endl;
            ans=max(ans,dp[j-1]);
        }
        cout<<ans<<endl;

    }
    return 0;
}
