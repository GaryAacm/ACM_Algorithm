/*通过枚举公因数的思路来一个个处理GCD问题*/
#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn=2e5+10;

ll t,x,n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>x>>n;
        ll ans=0;
        for(ll i=1;i*i<=x;i++)
        {
            if(x%i==0)
            {
                ll k=x/i;
                if(k>=n)
                {
                    ans=max(ans,i);
                }
                if(i!=x/i)
                {
                    k=i;
                    if(k>=n)
                        ans=max(ans,x/i);
                }
            }
        }
        cout<<ans<<endl;
    }
}
