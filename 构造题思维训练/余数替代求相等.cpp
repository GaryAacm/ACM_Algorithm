#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn=2e5+10;

int t,n,a[maxn];

void solve()
{
    cin>>n;
    bool f0=false,f1=false;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==0) f0=true;
        if(a[i]==1) f1=true;
    }

    if(f1&&f0) cout<<"NO"<<endl;
    else if(!f1) cout<<"YES"<<endl;//不存在1
    else//有1无0
    {
        sort(a+1,a+1+n);
        //n=unique(a+1,a+n+1)-a-1;
        bool flag=true;
        for(int i=1;i<n;i++)
        {
            if(a[i]+1==a[i+1])
            {
                flag=false;
                cout<<"NO"<<endl;
                break;
            }
        }
        if(flag) cout<<"YES"<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}
