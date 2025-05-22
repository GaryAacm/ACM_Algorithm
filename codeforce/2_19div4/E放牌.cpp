#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
#define int long long
const int maxn=2e5+10;


int t,n,k;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        if(k<=(n+1)/2) cout<<(ll)(2*k-1)<<endl;
        else if(k<=(n+1)/2+(n+2)/4) cout<<(ll)((k-(n+1)/2)*2-1)*2<<'\n';
        else
        {
            cout<<(ll)((k-((n+1)/2+(n+2)/4))*2-1)*4<<'\n';

        }
    }
    return 0;
}
