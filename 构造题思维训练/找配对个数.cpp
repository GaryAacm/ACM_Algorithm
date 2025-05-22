#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+10;
//提供了一个思路，就是处理将数字排列，然后连边，找没有相连的边的处理
int t,n,m,a[maxn];
int x,y;
void init()
{
    for(int i=1;i<=n;i++) a[i]=n;//初始能够到达的终点是n
}

void solve()
{
    cin>>n>>m;
    init();
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y;
        if(x>y) swap(x,y);
        a[x]=min(a[x],y-1);//更新到达的点
    }
    for(int i=n-1;i>=1;i--)
    {
        a[i]=min(a[i],a[i+1]);//前面的去不了后面的点

    }

    int ans=0;
    for(int i=1;i<=n;i++)
    {
        ans+=a[i]-i+1;
    }
    cout<<ans<<endl;
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
