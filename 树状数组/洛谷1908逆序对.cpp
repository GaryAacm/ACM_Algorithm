#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
ll b[maxn],c[maxn],a[maxn];
ll n,k;

ll lowbit(ll k)
{
    return k&(-k);
}

void update(ll p,ll k)
{
    while(p<=n)
    {
        c[p]+=k;//更新时树上节点的值要单独存，和b数组作为节点位置要分开
        p+=lowbit(p);
    }
}

ll sum(ll p)
{
    ll ans=0;
    while(p>0)
    {
        ans+=c[p];
        p-=lowbit(p);
    }
    return ans;
}

int main()
{
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        b[i]=a[i];
    }
    sort(b+1,b+1+n);
    int tot=unique(b+1,b+1+n)-b-1;
    for(int i=1;i<=n;i++)
    {
        a[i]=lower_bound(b+1,b+1+tot,a[i])-b;
    }
    //离散化
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        update(a[i],1);
        ans+=(i-sum(a[i]));
    }
    printf("%lld",ans);
    return 0;
}
