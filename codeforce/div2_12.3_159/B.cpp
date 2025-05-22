#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
int tc;
ll n,p,l,t;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);


    cin>>tc;
    while(tc--)
    {
        cin>>n>>p>>l>>t;
        ll low=0,high=n;
        while(low<=high)
        {
            ll mid=(low+high)>>1;
            ll v1=mid*l;
            ll v2=min(mid*2,(n+6)/7)*t;
            if(v1+v2>=p)
                high=mid-1;
            else
                low=mid+1;
        }
        cout<<n-low<<endl;
    }

    return 0;
}
