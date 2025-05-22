#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn=2e5+10;

int t,n;
string s;
int cnt[30];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n>>s;
        memset(cnt,0,sizeof(cnt));
        int maxx=-1;
        for(int i=0;i<s.length();i++)
        {
            cnt[s[i]-96]++;
        }
        for(int i=1;i<=26;i++)
        {
            maxx=max(maxx,cnt[i]);
        }
        int k=n-maxx;
        if(maxx>=k) cout<<maxx-k<<'\n';
        else
        {
            if(n&1) cout<<1<<'\n';
            else cout<<0<<'\n';
        }
    }
}
