
#include <bits/stdc++.h>
using namespace std;

#define r(x) x=read()
#define c getchar()
#define ll long long
inline int read()
{
    int w=1,s=0;
    char ch=c;
    while(ch>'9'||ch<'0'){if(ch=='-')w=-1;ch=c;}
    while(ch>='0'&&ch<='9')s=(s<<1)+(s<<3)+ch-'0',ch=c;
    return s*w;
}
const int maxn=5e4+10;
int n,k,cnt,x,y,fnl;
int f[maxn][21],depth[maxn],head[maxn],sum[maxn];

struct node
{
    int to,next;
}edge[maxn<<1];

inline void add(int from,int to)
{
    edge[++cnt].next=head[from];
    edge[cnt].to=to;
    head[from]=cnt;
}

inline void dfs(int u,int fa)
{
    f[u][0]=fa;
    depth[u]=depth[fa]+1;
    for( int i=1;(1<<i)<=depth[u];++i)
       f[u][i]=f[f[u][i-1]][i-1];
    for( int i=head[u];i;i=edge[i].next)
    {

        if(edge[i].to!=fa) dfs(edge[i].to,u);
    }
}
inline int lca(int u,int v)
{
    if(depth[u]<depth[v])swap(u,v);
    for( int i=20;i>=0;--i)
    {
        if((1<<i)<=depth[u]-depth[v])
            u=f[u][i];
    }
    if(u==v) return v;
    for( int i=20;i>=0;--i)
    {
        if(f[u][i]!=f[v][i])
        {
            u=f[u][i];
            v=f[v][i];
        }
    }
    return f[u][0];
}
inline void Gmax(int u,int fa)
{
    for( int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==fa) continue;

        Gmax(v,u);
        sum[u]+=sum[v];

    }
    fnl=max(fnl,sum[u]);
}

int main()
{

    r(n),r(k);
    for( int i=1,u,v;i<=n-1;++i)
    {
        r(u),r(v);
        add(u,v),add(v,u);
    }
    dfs(1,0);
    while(k--)
    {

        scanf("%d%d",&x,&y);
        int fa=lca(x,y);
        ++sum[x],++sum[y];
        --sum[fa],--sum[f[fa][0]];
    }
    Gmax(1,0);
    printf("%d",fnl);
    return 0;
}
