/*这里关键是处理重复元素，两个数组的重复元素，利用好set来处理*/
#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn=2e5+10;

int n,t,m,k;
int is[maxn*2];
int a[maxn],b[maxn];

void solve()
{
    set<int> st1,st2,st;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]>=1&&a[i]<=k)
        {
            st1.insert(a[i]);
            st.insert(a[i]);
        }
    }
    for(int i=1;i<=m;i++)
    {
        cin>>b[i];
        if(b[i]>=1&&b[i]<=k)
        {
            st2.insert(b[i]);
            st.insert(b[i]);
        }

    }
    if(st.size()==k&&st1.size()>=k/2&&st2.size()>=k/2)
    {
        cout<<"Yes"<<endl;
    }
    else
        cout<<"No"<<endl;
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
}
