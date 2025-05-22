#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;

int n,l,r,a[maxn];

int Find(int x)
{
    int L=l,R=r;
    while(L<R)
    {
        int mid=(L+R)>>1;
        if(mid>=x) R=mid;
        else L=mid+1;
    }

    return L;
}

int main()
{
    //freopen("D:\\Ëã·¨½ø½×\\At coder\\2023_11.25\\in.txt","r",stdin);
    cin>>n>>l>>r;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];

        int ans=Find(a[i]);
        cout<<ans<<' ';
    }
    return 0;

}
