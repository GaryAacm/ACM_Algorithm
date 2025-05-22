#include<bits/stdc++.h>
const int maxn=2005;
typedef long long ll;
using namespace std;

struct edge
{
    int to, dis, next;
};

edge e[maxn];
int head[maxn],  cnt,ss[maxn];//二维dis第二位表示当前的速度
ll dis[maxn][maxn];
bool vis[maxn][maxn];

void init()
{
    for(int i=0;i<maxn;i++)
    {
        e[i].next=0;
        head[i]=0;
    }
    cnt=0;
}
inline void add_edge( int u, int v, int d )
{
    cnt++;
    e[cnt].dis = d;
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

struct node
{
    ll dis;
    int pos,speed;
    bool operator <( const node &x )const
    {
        return x.dis < dis;
    }
};

int t,n,m,u,v,w;
void dijkstra(int s)
{
    memset(dis, 0x3f, sizeof dis);
	memset(vis, 0, sizeof vis);
	priority_queue<node> q;
    while(!q.empty()) q.pop();

    dis[s][ss[s]] = 0;
    q.push( ( node ){0, s, ss[s]} );
    while( !q.empty() )
    {
        node tmp = q.top();
        q.pop();
        int x = tmp.pos, sp = tmp.speed;
        if( vis[x][sp] )
            continue;
        vis[x][sp] = 1;
        for( int i = head[x]; i; i = e[i].next )
        {
            int y = e[i].to;

            //不换速度
            if( dis[y][sp] > dis[x][sp] + e[i].dis * sp )
            {
                dis[y][sp] = dis[x][sp] + e[i].dis * sp;
                q.push( ( node ){dis[y][sp], y, sp} );

            }

            //换速度
            if(dis[y][ss[y]]>dis[x][sp]+e[i].dis * sp)
            {
                dis[y][ss[y]] = dis[x][sp] + e[i].dis * sp;
                q.push( ( node ){dis[y][ss[y]], y, ss[y]} );
            }
        }
    }
}


int main()
{
   scanf("%d",&t);
   while(t--)
   {
       scanf("%d%d",&n,&m);
       init();
       for(int i=1;i<=m;++i)
       {
           scanf("%d%d%d",&u,&v,&w);
           if(u==v) continue;
           add_edge(u,v,w);
           add_edge(v,u,w);
       }
       for(int i=1;i<=n;i++)
       {
           scanf("%d",&ss[i]);
       }
       //sort(ss+1,ss+n);
       dijkstra(1);
       ll minn = 1e18;
       for(int i=1;i<=n;i++)
       {
           minn=min(dis[n][ss[i]],minn);
       }
       printf("%lld\n",minn);
   }

   return 0;
}
