#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e5+10;

int n,c[maxn],Q[maxn],dis[maxn],f[maxn];
int sum=0,ans=1e9;
//----------------------------
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
//----------------------------------

int dfs1(int u,int fa)
{
    int tot=0;
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v!=fa)
        {
            int s=dfs1(v,u);//子树上牛的数量
            dis[u]+=dis[v]+edge[i].w*s;//计算全部节点到u的距离
            tot+=s;//计算当前节点子节点牛的数量
        }
    }
    return Q[u]=tot+c[u];//Q记录牛的数量
}

//记录回退点的距离
//回退的时候这个节点和子节点都要回退，其余节点要前进
void dfs2(int u,int fa)
{
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v!=fa)
        {
            int s=edge[i].w;
            f[v]=f[u]-Q[v]*s+(sum-Q[v])*s;//所有的原来在1节点，然后子树上的回退，其余的前进
            dfs2(v,u);
        }
    }
}

//----------------------------------



signed main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
        sum+=c[i];
    }

    int u,v,w;
    for(int i=1;i<n;i++)
    {
        cin>>u>>v>>w;
        add(u,v,w);
        add(v,u,w);
    }
    dfs1(1,1);

    dfs2(1,1);

    for(int i=1;i<=n;i++)
    {
        ans=min(ans,f[i]);
    }

    cout<<ans+dis[1]<<endl;


    return 0;
}
