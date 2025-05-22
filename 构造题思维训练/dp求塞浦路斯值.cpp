/*想要数据大，就要尽可能多分段，只要贡献正数就分段，保证后面的大数为正数
多分段前提是保证分段后面的数贡献为正*/
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
            ans+=k*a[i];//一段一段计算
       }
       cout<<ans<<endl;
    }

    return 0;
}
