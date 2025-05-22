#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
ll t,n;
ll a[maxn];
int main()
{
    cin>>t;
    //scanf("%lld",&t);
    while(t--)
    {
        cin>>n;
        ll maxx=-1;
        ll sum=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            maxx=max(maxx,a[i]);
            sum+=a[i];
        }
        ll s=sum-maxx;
        if(maxx-1<=s) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}

