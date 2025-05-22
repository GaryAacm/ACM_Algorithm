#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e6+1;
//const int maxn=2001;

ll D,a[maxn],b[maxn];

int main()
{
    //cin>>D;
    scanf("%lld",&D);
    ll ans=LLONG_MAX;
   for(ll i=1;i*i<=D;i++)//一个一个枚举即可，比二分好点
   {
       ll res=i*i;
       ll k=sqrt(abs(D-res));
       ll s=k+1;
       ans=min(ans,min(abs(D-res-k*k),abs(D-res-s*s)));
   }

   printf("%lld",ans);

    return 0;
}
