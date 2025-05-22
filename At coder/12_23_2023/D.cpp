#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
ll n,q,temp;
ll a[maxn];
ll sum[maxn];
int main()
{
    cin.tie(0);
    cout.tie(0);
    //freopen("D:\\Ëã·¨½ø½×\\At coder\\12_23_2023\\in.txt","r",stdin);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
    {
        sum[i]+=a[i]+sum[i-1];
    }
    while(q--)
    {
        cin>>temp;
        ll l=1,r=n;
        while(l<=r)
        {
            ll mid=l+r>>1;
            if(sum[mid]>temp)
                r=mid-1;
            else l=mid+1;
        }
        cout<<l-1<<endl;
    }
}
