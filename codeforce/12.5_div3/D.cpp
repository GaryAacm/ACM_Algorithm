#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn=2e5+10;
int t,n,l[maxn],r[maxn],k;
int maxx;
bool check(int x)
{

    int a1=0,a2=0;
    for(int i=1;i<=n;++i)
    {
        a1-=x;
        a2+=x;
        a1=max(a1,l[i]);
        a2=min(a2,r[i]);//找出每次移动的合法区间位置
        if(a1>a2) return false;
    }
    return true;
}

int solve()
{
    int L=0,R=1e9;
    while(L<=R)
    {
        int mid=(L+R)>>1;
        if(check(mid))
        {
            R=mid-1;
        }
        else
            L=mid+1;
    }
    return L;

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n;
        maxx=-1;
        for(int i=1;i<=n;++i)
        {
            cin>>l[i]>>r[i];
            maxx=max(maxx,r[i]);
        }
        int k=solve();
        cout<<k<<endl;

    }
    return 0;
}
