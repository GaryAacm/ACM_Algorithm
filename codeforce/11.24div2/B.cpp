#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
typedef long long ll;
ll t,n;
ll a[maxn];


int main()
{
    //freopen("D:\\Ëã·¨½ø½×\\codeforce\\11.24div2\\in.txt","r",stdin);
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        if(n==1)
        {
            ll temp;
            scanf("%lld",&temp);
            printf("%lld\n",temp-1);
        }
        else
        {
            for(int i=1;i<=n;i++)
        {
            scanf("%lld",&a[i]);
        }
        a[n+1]=0;
        ll ans=0;
        for(int i=2;i<=n;i++)
        {
            if(a[i]<a[i-1]) ans+=a[i-1]-a[i];

        }
         ans+=a[n]-a[n+1]-1;
        printf("%lld\n",ans);
        }
    }

    return 0;
}

