#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
typedef long long ll;
ll a[maxn],sum[maxn];
ll n,t;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);


    cin>>t;
    while(t--)
    {
        cin>>n;
        for(ll i=1;i<=n;++i)
        {
            cin>>a[i];
            sum[i]=sum[i-1]+a[i];
        }

       ll ans=0,k=0;
       for(int i=1;i<=n;i++)
       {
           if(i==1||sum[n]-sum[i-1]>=0) k++;//贪心思想，就是后面的大于0就多划分一段
              ans+=k*a[i];
       }
       cout<<ans<<endl;
    }

    return 0;
}
