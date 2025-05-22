#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+10;
typedef long long ll;
struct node
{
    ll u,v,w;
}e[maxn<<1];

struct point
{
    ll x,y;
}p[maxn];

ll build,connect,paths[maxn],bui[maxn],pathe[maxn];
ll or1,or2;
ll cnt,f[maxn],n,m,s,t,u,v,w,x;
ll ans=0;
ll cost[maxn],kcost[maxn];
bool cmp(node x,node y)
{
    return x.w<y.w;
}

ll finded(ll x)
{
    if(f[x]==x) return x;
    return f[x]=finded(f[x]);
}

void join(ll x,ll y)
{
        ll xx=finded(x);
        ll yy=finded(y);
        if(xx!=yy) f[xx]=yy;
}

void addedge(ll x,ll y,ll z)
{
        cnt++;
        e[cnt].u=x;
        e[cnt].v=y;
        e[cnt].w=z;
}

void kruskal()
{
    ll j=1;
    while(j<=cnt)
    {
            if(finded(e[j].u)!=finded(e[j].v))
            {
                ans+=e[j].w;
                join(e[j].u,e[j].v);
                if(e[j].u==0)
                {
                    build++;
                    bui[or1++]=e[j].v;
                }
                else
                {
                    connect++;
                    paths[or2]=e[j].u;
                    pathe[or2++]=e[j].v;

                }
            }
            j++;
    }
    cout<<ans<<'\n';
    cout<<build<<'\n';
    for(ll i=0;i<or1;i++)
        cout<<bui[i]<<' ';
    cout<<'\n'<<connect<<'\n';
    for(ll i=0;i<or2;i++)
        cout<<paths[i]<<' '<<pathe[i]<<'\n';


}

ll distance(ll u,ll v)
{
    return ((kcost[u]+kcost[v])*(abs(p[u].x-p[v].x)+abs(p[u].y-p[v].y)));
}

void solve()//¼ÆËãÈ¨Öµ
{
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=n;j++)
        {
            if(i<j)
            {
                ll w=distance(i,j);
                addedge(i,j,w);
            }
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;i++)
    {
        cin>>p[i].x>>p[i].y;
    }
    for(ll i=1;i<=n;++i)
    {
        cin>>cost[i];
    }
    for(ll i=1;i<=n;i++)
        cin>>kcost[i];

    for(ll i=0;i<=n;i++) f[i]=i;

    for(ll i=1;i<=n;i++) addedge(0,i,cost[i]);

    solve();
    sort(e+1,e+1+cnt,cmp);
    kruskal();

    return 0;

}


