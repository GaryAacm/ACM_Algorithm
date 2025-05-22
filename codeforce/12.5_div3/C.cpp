#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn=2e5+10;
int t,n;
char s[maxn];
int cnt[30];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n;
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<n;i++)
        {
            cin>>s[i];
            cnt[s[i]-'a']++;

        }
        int mx=-1;
        for(int i=0;i<30;i++)
        {
            mx=max(mx,cnt[i]);
        }
        if(mx>=n-mx) cout<<mx-(n-mx)<<endl;
        else
        {
            cout<<int(n&1)<<endl;
        }
    }

    return 0;
}
