#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn=2e5+10;

int t,n;
int a[maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        sort(a+1,a+1+n);
        ll sum=0;
        for(int i=2;i<=n;i++)
        {
            sum+=a[i]-a[i-1];
        }
        cout<<sum<<endl;
    }
}
