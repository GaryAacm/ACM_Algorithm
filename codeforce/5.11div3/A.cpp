#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn=1005;
int gcd(int x,int y)
{
    return y? gcd(y,x%y):x;
}

ll t,n;
signed main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        int ans=-1,val=0;
        for(int i=1;i<n;i++)
        {
            if(val<gcd(n,i)+i)
            {
                val=gcd(n,i)+i;
                ans=i;
            }
        }
        cout<<ans<<endl;
    }
}

