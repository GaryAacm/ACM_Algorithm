#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MaxN = 100010, MaxM = 100010;

struct Edge
{
    int to, dis, next;
};

Edge edge[MaxM];
int head[MaxN], dis[MaxN], cnt;
int pre[MaxM];
bool vis[MaxM];
int n, m, s;
//就是调整最短路，通过每次的操作来进行维护，这个思想要记住
inline void add_edge( int u, int v, int d)
{
    cnt++;
    edge[cnt].dis = d;
    edge[cnt].to = v;
    edge[cnt].next = head[u];
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
    node(int d,int x) {dis=d,pos=x;}
};



void init()
{
    for(int i=1;i<=n;i++)
    {
        dis[i]=1e9;
    }
}
queue<int> q;
int h[MaxM],t[5005];
bool spfa(int s)
{
    memset(h,63,sizeof(h));
    h[s]=0;
    vis[s]=1;
    q.push(s);
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        vis[x]=0;
        for(int i=head[x];i;i=edge[i].next)
        {
            int v=edge[i].to;
            //if(vis[v]) continue;
            if(h[v]>h[x]+edge[i].dis)
            {
                h[v]=h[x]+edge[i].dis;
                if(!vis[v])
                {
                    vis[v]=1;
                    q.push(v);
                    t[v]++;
                    if(t[v]==n+1) return false;
                }
            }

        }
    }
    return true;
}

void dijkstra(int s)
{
    priority_queue<node> Q;
    memset(vis, 0, sizeof(vis));
    dis[s] = 0;
    Q.push( ( node ){0, s} );
    while( !Q.empty() )
    {
        node tmp = Q.top();
        Q.pop();
        int x = tmp.pos, d = tmp.dis;
        if(vis[x]) continue;
        vis[x]=1;
        for( int i = head[x]; i; i = edge[i].next )
        {
            int y = edge[i].to;
            if( dis[y] > dis[x] + edge[i].dis) //用加上最值来维护
            {
                dis[y] = dis[x] + edge[i].dis;
                if(!vis[y]) Q.push( ( node ){dis[y], y} );

            }
        }
    }
}

signed main()
{
    cin>>n>>m;
    int u,v,w;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v>>w;
        add_edge(u,v,w);
    }
    for(int i=1;i<=n;i++) add_edge(0,i,0);


    if(!spfa(0)) //判断一次
    {
        cout<<-1<<endl;
        return 0;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=head[i];j;j=edge[j].next)
            edge[i].dis+=h[i]-h[edge[j].to];
    }
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        init();
        ans=0;
        dijkstra(i);
        for(int j=1;j<=n;j++)
        {
            if(dis[j]==1e9) ans+=j*dis[j];
            else
                ans+=j*(dis[j]+h[j]-h[i]);
        }
        cout<<ans<<endl;
    }



    return 0;


}

/*
#include <cstring>
#include <iostream>
#include <queue>
#define INF 1e9
using namespace std;
struct edge {
  int v, w, next;
} e[10005];
struct node {
  int dis, id;
  bool operator<(const node& a) const { return dis > a.dis; }
  node(int d, int x) { dis = d, id = x; }
};
int head[5005], vis[5005], t[5005];
int cnt, n, m;
long long h[5005], dis[5005];
void addedge(int u, int v, int w) {
  e[++cnt].v = v;
  e[cnt].w = w;
  e[cnt].next = head[u];
  head[u] = cnt;
}
bool spfa(int s) {
  queue<int> q;
  memset(h, 63, sizeof(h));
  h[s] = 0, vis[s] = 1;
  q.push(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    vis[u] = 0;
    for (int i = head[u]; i; i = e[i].next) {
      int v = e[i].v;
      if (h[v] > h[u] + e[i].w) {
        h[v] = h[u] + e[i].w;
        if (!vis[v]) {
          vis[v] = 1;
          q.push(v);
          t[v]++;
          if (t[v] == n + 1) return false;
        }
      }
    }
  }
  return true;
}
void dijkstra(int s) {
  priority_queue<node> q;
  for (int i = 1; i <= n; i++) dis[i] = INF;
  memset(vis, 0, sizeof(vis));
  dis[s] = 0;
  q.push(node(0, s));
  while (!q.empty()) {
    int u = q.top().id;
    q.pop();
    if (vis[u]) continue;
    vis[u] = 1;
    for (int i = head[u]; i; i = e[i].next) {
      int v = e[i].v;
      if (dis[v] > dis[u] + e[i].w) {
        dis[v] = dis[u] + e[i].w;
        if (!vis[v]) q.push(node(dis[v], v));
      }
    }
  }
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    addedge(u, v, w);
  }
  for (int i = 1; i <= n; i++) addedge(0, i, 0);
  if (!spfa(0)) {
    cout << -1 << endl;
    return 0;
  }
  for (int u = 1; u <= n; u++)
    for (int i = head[u]; i; i = e[i].next) e[i].w += h[u] - h[e[i].v];
  for (int i = 1; i <= n; i++) {
    dijkstra(i);
    long long ans = 0;
    for (int j = 1; j <= n; j++) {
      if (dis[j] == INF)
        ans += j * INF;
      else
        ans += j * (dis[j] + h[j] - h[i]);
    }
    cout << ans << endl;
  }
  return 0;
}
*/
