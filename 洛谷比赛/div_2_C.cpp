#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,k,l;
int t;

int main()
{
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>k>>l;
        if(l&1)//ÆæÊı
        {
            int cnt=0;
            ll ss=1;
            while(ss<l)
            {
                ss=ss<<1;
                cnt++;
                //cout<<ss<<endl;
            }
            if(cnt>k) cout<<"No\n";
            else
            {
                if(cnt==k) cout<<"No\n";
                else
                {
                    ll s=ss-l;
                    if(cnt+s>k) cout<<"No\n";
                    else if(cnt+s==k) cout<<"Yes\n";
                    else{
                        ll ssa=l-(ss>>1)+ss-l+1;
                        ll ed=k-cnt-s;

                        if(ed%ssa==0) cout<<"Yes\n";
                        else cout<<"No\n";

                    }
                }
            }
        }
        else
        {
            int cnt=0;
            ll ss=l;
            while(ss>0)
            {
                ss=ss>>1;
                cnt++;
            }
            if(cnt>k) cout<<"No\n";
            else
            {
                if(cnt==k) cout<<"Yes\n";
                else
                {
                    ll s=l>>1;
                    ll sk=l-s;
                    if((cnt-k)%(sk+1)==0) cout<<"Yes\n";
                    else cout<<"No\n";
                }
            }
        }
    }
}
