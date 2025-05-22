#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+10;

int t,n,leftt[maxn],rightt[maxn],dp[maxn][2];
string s;

int dfs(int x)
{
    if(leftt[x]==0&&rightt[x]==0) return 0;
    int res=0x3f3f3f3f;
    if(leftt[x]) res=min(res,dfs(leftt[x])+(s[x]!='L'));
    if(rightt[x]) res=min(res,dfs(rightt[x])+(s[x]!='R'));
    return res;
}

void solve()
{
    cin>>n;
    cin>>s;
    s=" "+s;
    for(int i=1;i<=n;i++)
    {
        cin>>leftt[i]>>rightt[i];
    }

    cout<<dfs(1)<<'\n';
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
