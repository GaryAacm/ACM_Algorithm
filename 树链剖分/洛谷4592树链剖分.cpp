#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
#include<cstdio>
using namespace std;
typedef long long lt;

int read()
{
    int f=1,x=0;
    char ss=getchar();
    while(ss<'0'||ss>'9'){if(ss=='-')f=-1;ss=getchar();}
    while(ss>='0'&&ss<='9'){x=x*10+ss-'0';ss=getchar();}
    return f*x;
}

const int maxn=500010;
int n,m;
struct node{int v,nxt;}E[maxn<<1];
int head[maxn],tot;
int val[maxn],size[maxn],top[maxn],dep[maxn];
int fa[maxn],son[maxn],num[maxn],pos[maxn],cnt;
int rt[2][maxn<<4],sz[2],sum[2][maxn<<4],nxt[2][maxn<<4][2];

void add(int u,int v)
{
    E[++tot].nxt=head[u];
    E[tot].v=v;
    head[u]=tot;
}

void dfs1(int u,int pa)
{
    size[u]=1;
    for(int i=head[u];i;i=E[i].nxt)
    {
        int v=E[i].v;
        if(v==pa) continue;
        dep[v]=dep[u]+1; fa[v]=u;
        dfs1(v,u);
        size[u]+=size[v];
        if(size[v]>size[son[u]]) son[u]=v;
    }
}

void dfs2(int u,int tp)
{
    top[u]=tp; num[u]=++cnt; pos[cnt]=u;
    if(son[u]) dfs2(son[u],tp);
    for(int i=head[u];i;i=E[i].nxt)
    {
        int v=E[i].v;
        if(v==fa[u]||v==son[u]) continue;
        dfs2(v,v);
    }
}

int update(int pre,int x,int cntt,int p)
{
    int rt=++sz[p]; sum[p][rt]=sum[p][pre]+1;
    if(cntt<0) return rt;
    int d=x>>cntt&1;
    nxt[p][rt][d^1]=nxt[p][pre][d^1];
    nxt[p][rt][d]=update(nxt[p][pre][d],x,cntt-1,p);
    return rt;
}

int query1(int u,int v,int x,int cntt)
{
    if(cntt<0) return 0;
    int d=x>>cntt&1;
    int ss=sum[0][nxt[0][v][d^1]]-sum[0][nxt[0][u][d^1]];
    if(ss>0) return (1<<cntt)+query1(nxt[0][u][d^1],nxt[0][v][d^1],x,cntt-1);
    else return query1(nxt[0][u][d],nxt[0][v][d],x,cntt-1);
}

int LCA(int u,int v)
{
    while(top[u]!=top[v])
    {
        if(dep[top[u]]>dep[top[v]]) u=fa[top[u]];
        else v=fa[top[v]];
    }
    return dep[u]<dep[v]?u:v;
}

void dfs(int u)
{
    rt[1][u]=update(rt[1][fa[u]],val[u],30,1);
    for(int i=head[u];i;i=E[i].nxt)
    if(E[i].v!=fa[u]) dfs(E[i].v);
}

int query2(int u,int v,int lca,int gra,int x,int cntt)
{
    if(cntt<0) return 0;
    int d=x>>cntt&1;
    int lcu=nxt[1][u][d^1],lcv=nxt[1][v][d^1],lc=nxt[1][lca][d^1],lcg=nxt[1][gra][d^1];
    int ss=sum[1][lcu]+sum[1][lcv]-sum[1][lc]-sum[1][lcg];
    if(ss>0) return (1<<cntt)+query2(lcu,lcv,lc,lcg,x,cntt-1);
    else return query2(nxt[1][u][d],nxt[1][v][d],nxt[1][lca][d],nxt[1][gra][d],x,cntt-1);
}

int main()
{
    n=read();m=read();
    for(int i=1;i<=n;++i) val[i]=read();
    for(int i=1;i<n;++i)
    {
        int u=read(),v=read();
        add(u,v); add(v,u);
    }

    dfs1(1,0); dfs2(1,1);//Ê÷ÆÊ½¨Ê÷
    for(int i=1;i<=n;++i)
    rt[0][i]=update(rt[0][i-1],val[pos[i]],30,0);

    dfs(1);//ÉîËÑ½¨Ê÷

    while(m--)
    {
        int opt=read(),x=read(),y=read();
        if(opt==1) printf("%d\n",query1(rt[0][num[x]-1],rt[0][num[x]+size[x]-1],y,30));
        else if(opt==2)
        {
            int z=read(),lca=LCA(x,y);
            printf("%d\n",query2(rt[1][x],rt[1][y],rt[1][lca],rt[1][fa[lca]],z,30));
        }
    }
    return 0;
}
