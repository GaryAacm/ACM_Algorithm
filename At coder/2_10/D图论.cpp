#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn=2e6+10;

struct edge
{
	ll nxt,to,dis;

}edge[maxn*2];

ll head[maxn],tot;
void addedge(ll x,ll y,ll z)
{
	edge[++tot].nxt=head[x],edge[tot].to=y,edge[tot].dis=z,head[x]=tot;
}
//-------------存图---------------------//

//-------最短路-------------------//
struct node
{
    ll dis;
    ll pos;
    bool operator <( const node &x )const
    {
        return x.dis < dis;
    }
};

priority_queue<node> q;

ll dis[maxn];
ll vis[maxn];
void dij()
{
    dis[1] = 0;
    q.push( ( node ){0, 1} );
    while( !q.empty() )
    {
        node tmp = q.top();
        q.pop();
        ll x = tmp.pos, d = tmp.dis;
        if(vis[x])
            continue;
        vis[x] = 1;
        for( int i = head[x]; i; i = edge[i].nxt )
        {
            ll y = edge[i].to;
            if( dis[y] > dis[x] + edge[i].dis )
            {
                dis[y] = dis[x] + edge[i].dis;
                if( !vis[y] )
                {
                    q.push( ( node ){dis[y], y} );
                }
            }
        }
    }
}


//------------------正解--------------------------//
ll n,a,b,x;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n;
    for(int i = 1; i <= n; ++i)dis[i] = 9223372036854775807;
    for(int i=1;i<n;i++)
    {
        cin>>a>>b>>x;
        addedge(i,i+1,a);
        addedge(i,x,b);

    }
    dij();
    cout<<dis[n];

}

