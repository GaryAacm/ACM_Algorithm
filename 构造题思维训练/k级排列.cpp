#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn=2e5+10;

int t,ans[maxn],n,k;

void solve()
{
    cin>>n>>k;
    int cnt1=1,cnt2=1,tmp=1;
    for(int i=1;i<=k;i++)
    {
        cnt1=i;
        cnt2=i;
        vector<int> s;
        while(cnt1<=n)
        {
            s.push_back(tmp);
            tmp++;
            cnt1+=k;
        }
        if(!(i&1))
        {
            reverse(s.begin(),s.end());

        }
        for(int aa=0;aa<s.size();aa++)
        {
            ans[cnt2]=s[aa];
            cnt2+=k;
        }

    }

    for(int i=1;i<=n;i++)
    {
        cout<<ans[i]<<' ';
    }
    cout<<endl;
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
