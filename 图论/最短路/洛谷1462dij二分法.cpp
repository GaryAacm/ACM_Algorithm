#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9+10;
const int MaxN = 500010, MaxM = 500010;

struct edge
{
    int to, dis, next;
};

edge e[MaxM<<1];
int head[MaxN], dis[MaxN], cnt;
bool vis[MaxN];
int s;
int n,m,b,u,v,w;
int cost[MaxN];
inline void addedge( int u, int v, int d )
{
    cnt++;
    e[cnt].dis = d;
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

struct node
{
    int dis;
    int pos;
    bool operator <( const node &x )const
    {
        return x.dis < dis;
    }
};


bool dijkstra(int mid)
{
    for(int i=1;i<=n;i++)
    {
        dis[i]=INF;
        vis[i]=0;
    }
    priority_queue<node> q;
    dis[1] = 0;

    while(!q.empty()) q.pop();

    q.push( ( node ){0, 1} );
    while( !q.empty() )
    {
        node tmp = q.top();
        q.pop();
        int x = tmp.pos, d = tmp.dis;
        if( vis[x] )
            continue;
        vis[x] = 1;
        for( int i = head[x]; i; i = e[i].next )
        {
            int y = e[i].to;
            if( dis[y] > dis[x] + e[i].dis && cost[y]<=mid &&!vis[y])
            {
                dis[y] = dis[x] + e[i].dis;
                q.push( ( node ){dis[y], y});

            }
        }
    }
    if(dis[n]>b) return false;
    else
        return true;
}


int main()
{
    cin.tie(0);
    cout.tie(0);
    //freopen("C:\\Users\\asus\\Desktop\\in.txt","r",stdin);
    cin>>n>>m>>b;
    int r=0;
    for(int i=1;i<=n;++i)
    {
        cin>>cost[i];
        r=max(cost[i],r);
    }
    for(int i=1;i<=m;++i)
    {
        cin>>u>>v>>w;
        if(u==v) continue;
        addedge(u,v,w);
        addedge(v,u,w);
    }
    int l=max(cost[1],cost[n]);

    int ans=0;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        //cout<<1<<endl;
        if(dijkstra(mid)){
            ans=mid;
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    if(!dijkstra(INF)) cout<<"AFK";
    else cout<<ans<<endl;
}
