#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n,cnt;
int a[150005];
int b[150005];
ll sum[150005];

int main()
{
    //freopen("D:\\Ëã·¨½ø½×\\codeforce\\11.17div3\\in.txt","r",stdin);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        if(n==0) printf("0\n");
        else
        {
            memset(sum,0,sizeof(sum));

        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            sum[i]=sum[i-1]+a[i];
        }

    cnt=0;
        memset(b,0,sizeof(b));
    for(int k=1;k<=n/k;k++)
    {

        if(n%k==0)
        {
            //cout<<k<<endl<<n/k<<endl;
            b[cnt++]=k;
            b[cnt++]=n/k;
        }
    }


        ll ans=0;
        //cout<<ans<<endl;


        for(int i=0;i<cnt;i++)
        {

            if(b[i]==n) continue;
            ll maxx=LLONG_MIN,minn=LLONG_MAX;

            for(int j=1;j<=n;j+=b[i])
            {

                //cout<<b[i]<<endl;


                maxx=max(maxx,sum[j+b[i]-1]-sum[j-1]);

                minn=min(minn,sum[j+b[i]-1]-sum[j-1]);
                //cout<<"max "<<maxx<<endl<<"min "<<minn<<endl;

            }

            //cout<<"²åÖµ"<<maxx-minn<<endl;

            ans=max(ans,maxx-minn);


        }

        printf("%lld\n",ans);
        }

    }

    return 0;
}
