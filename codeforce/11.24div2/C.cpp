#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
ll t,n,m;
ll a[maxn],b[maxn],num[maxn];


int main()
{
    //freopen("D:\\Ëã·¨½ø½×\\codeforce\\11.24div2\\in.txt","r",stdin);
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        ll minn=1e9+10;
        for(int i=1;i<=n;i++)
        {
            scanf("%lld",&a[i]);
            num[i]=a[i];
            minn=min(a[i],minn);
        }

        if(n==1) printf("0\n");
        else
        {
            ll order=0,ans=0;
            sort(num+1,num+1+n);
            m=unique(num+1,num+1+n)-1-num;
            while(num[m]!=num[1])
            {
                num[m]=(num[m]+num[1])/2;
                ans++;
                order++;
            }
            if(ans<=n)
            {
                printf("%lld\n",ans);
                for(int i=0;i<order;i++)
                    printf("%lld ",num[1]);
                printf("\n");
            }
            else
                printf("%lld\n",ans);

        }
    }
    return 0;
}
