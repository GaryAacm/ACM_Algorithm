#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e5+10;

//---------------------------------------------------------
struct Edge
{
	int next;
	int to;
	int w;
};

Edge edge[maxn*2];

int head[maxn];

int cnt = 0;

void add(int u, int v, int w)
{
    edge[++cnt].w = w;
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt;
}

//--------------------------------------------------------------------

int n,m,u,v,w;
int in[maxn],out[maxn];
double f[maxn];//细节处理问题，就是通过数组来记录，避免直接在dfs里面记录有误受到前面的影响
bool vis[maxn];
void dfs(int x)
{
    if(x==n)
    {
        f[x]=0;
        return ;
    }
    if(vis[x]) return ;
    vis[x]=1;
    for(int i=head[x];i;i=edge[i].next)
    {
        int to=edge[i].to;
        dfs(to);
        f[x]+=(f[to]+edge[i].w)/out[x];//通过期望累加来处理
    }

}


signed main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v>>w;
        add(u,v,w);
        out[u]++;
    }
    dfs(1);
    printf("%.2f",f[1]);

    return 0;
}
