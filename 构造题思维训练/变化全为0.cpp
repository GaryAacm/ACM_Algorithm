#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+10;

int t,n,a[maxn];


void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n-2;i++)
    {
        if(a[i]<0)
        {
            cout<<"NO"<<endl;
            return ;
        }
        else
        {

            a[i+1]-=a[i]*2;
            a[i+2]-=a[i];
            a[i]=0;
        }
    }
    if(a[n-1]==0&&a[n]==0)
    {
        puts("YES");
    }
    else
    {
        puts("NO");
    }

    return ;
}

signed main()
{
    cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}
