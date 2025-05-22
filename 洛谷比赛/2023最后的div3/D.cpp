#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,m;
ll a[1e6+1];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        if(m&1)
        {

        }
        else
        {
            for(int i=1;i<=n;i++)
            {
                cout<<a[i]<<" ";
            }
            cout<<endl;
        }
    }
}
