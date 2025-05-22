#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn=2e5+10;
ll t,n,a[maxn],dis[maxn];

ll gcd(ll x,ll y)
{
    return y? gcd(y,x%y):x;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("D:\\算法进阶\\codeforce\\div2_12.3_159\\in.txt","r",stdin);
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            //dis[i]=a[i]-a[i-1];
        }
        if(n==1)
            cout<<1<<endl;
        else if(n==2)
        {
            if((a[1]-a[0])%2==0)
               cout<<2<<endl;
            else cout<<3<<endl;

        }
        else
        {
            sort(a+1,a+1+n);
            for(int i=1;i<=n;i++)
                cout<<a[i]<<' ';
            cout<<endl;
            ll maxx=a[n],maxxx=a[n-1];
            ll ans=0;
            int j=0;
            for(int i=2,j=1;i<=n;i++)
            {
                dis[j++]=a[i]-a[i-1];
                cout<<a[i]-a[i-1];
                cout<<dis[j]<<endl;
            }
            //cout<<j<<endl;
            for(int i=1;i<j;i++)
                cout<<dis[i]<<' ';
            cout<<endl;
            ll dist=0;
            ll temp=gcd(dis[1],dis[2]);
            for(int i=3;i<j;i++)
            {
                if(dis[i]%temp==0) continue;
                temp=gcd(temp,dis[i]);
            }
            //cout<<temp<<endl;
            if(maxx>temp+maxxx)
            {
                for(int i=1;i<=n;i++)
                {
                    ans+=(maxx-a[i])/temp;
                }
                ans+=1;
            }
            else
            {
                maxx=maxx+temp;
                for(int i=1;i<=n;i++)
                {
                    ans+=(maxx-a[i])/temp;
                }
            }
            cout<<ans<<endl;

        }


    }

    return 0;
}
