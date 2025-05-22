#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e3+10;
int n,m,k;
//===============Á´Ê½ÏòÇ°=================//
struct Edge
{
    int to,nxt;
}edge[maxn];

int head[maxn],cnt=0;
void add_edge(int u,int v)
{
    edge[++cnt].to=v;
    edge[cnt].nxt=head[u];
    head[u]=cnt;
}

//============================================//
int vis[maxn],match[maxn];
bool solve(int u)
{
    for(int i=head[u];i;i=edge[i].nxt)
    {
        int v=edge[i].to;
        if(vis[v]) continue;
        vis[v]=1;
        if(!match[v]||solve(match[v]))
        {
            match[v]=u;
            return true;
        }
    }
    return false;
}

int u,v;
signed main()
{
    cin>>n;
    int ans=0;
    for(int i=1;i<=n*2;i++)
    {
        cin>>u>>v;
        add_edge(i,u);
        add_edge(i,u+n);
        add_edge(i,v);
        add_edge(i,v+n);
    }
    for(int i=1;i<=n*2;i++)
    {
        memset(vis,0,sizeof(vis));
        if(solve(i)) ans++;
    }

    cout<<ans<<endl;
}
