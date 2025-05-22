#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF=0x3f3f3f3f;
const int maxn=3e5+10;
//求最长上升子序列
int t,n;
int a[maxn],c[maxn];

int lowbit(int k)
{
    return k&(-k);
}

void update(int x,int p)
{
    while(x<=n)
    {
        c[x]=max(c[x],p);
        x+=lowbit(x);
    }
}

int ask(int x)
{
    int res=0;
    while(x>0)
    {
        res=max(res,c[x]);
        x-=lowbit(x);
    }
    return res;
}

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        c[i]=0;
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int tmp=ask(a[i]);
        if(tmp==1) ans++;
        update(a[i],tmp+1);
    }
    cout<<ans<<endl;
    return ;
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
