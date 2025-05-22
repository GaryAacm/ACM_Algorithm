#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll x,y,ans=0;
int main()
{
    cin>>x>>y;
    ll  maxx,minn;
    maxx=max(x,y);
    minn=min(x,y);

    while(maxx&&minn)
    {
        ans+=4*minn*(maxx/minn);
        x=maxx%minn;
        y=minn;
        maxx=max(x,y);
        minn=min(x,y);

    }
    cout<<ans<<endl;
    return 0;
}
