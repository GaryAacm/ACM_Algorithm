#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn=2e5+10;

int t,n,k;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        if(k==4*n-2)
        {
            cout<<2*n<<'\n';
        }
        else
        {
            cout<<(k+1)/2<<'\n';
        }
    }
}
