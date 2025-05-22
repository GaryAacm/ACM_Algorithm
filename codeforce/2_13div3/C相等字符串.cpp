#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn=2e5+10;

int t,n;
int a[maxn];
int cnt1,cnt2;
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
        cnt1=1;
        cnt2=1;
        int k1=a[1];
        int k2=a[n];
        for(int i=2;i<=n;i++)
        {
            if(a[i]==k1)
            {
                cnt1++;
            }
            else
            {
                break;
            }
        }
        for(int i=n-1;i>=1;i--)
        {
            if(a[i]==k2)
            {
                cnt2++;
            }
            else
            {
                break;
            }
        }

        if(cnt1==n) cout<<0<<'\n';
        else
        {
            if(k2==k1) cout<<n-cnt1-cnt2<<'\n';
            else cout<<n-max(cnt1,cnt2)<<'\n';
        }
    }
}
