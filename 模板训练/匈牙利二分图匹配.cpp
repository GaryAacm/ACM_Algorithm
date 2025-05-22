#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+10;
int n,m,k;
//===============链式向前=================//
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

//============匈牙利算法==================//
int match[maxn],vis[maxn];
bool dfs(int x)
{
    for(int i=head[x];i;i=edge[i].nxt)
    {
        int v=edge[i].to;
        if(vis[v]) continue;
        vis[v]=1;
        if(!match[v]||dfs(match[v])) //女生没有匹配或者可以被让出来
        {
            match[v]=x;//配对成功
            return true;
        }
    }
    return false;
}

//====================================================//


signed main()
{
    cin>>n>>m>>k;
    int u,v;
    for(int i=1;i<=k;i++)
    {
        cin>>u>>v;
        add_edge(u,v);
    }
    int ans=0;
    for(int i=1;i<=n;i++) //枚举每个男生
    {
        memset(vis,0,sizeof(vis));//每个男生选女生，每次女生可以被多次选
        if(dfs(i)) ans++;
    }

    cout<<ans<<endl;

    return 0;
}
