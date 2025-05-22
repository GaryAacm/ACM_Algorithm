
#include <bits/stdc++.h>
using namespace std;
#define re register
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
//f[i][j]表示以i为起点往上跳2^j个点，depth表示深度，sum为前缀和数组
struct node
{
    int to,next,dis;
}edge[maxn<<1];
inline void add(int from,int to)
{
    edge[++cnt].next=head[from];
    edge[cnt].to=to;
    head[from]=cnt;
}
inline int max(int a,int b){return a>b?a:b;}
inline void dfs(int u,int fa)
{
    f[u][0]=fa;//2^0=1,所以f[u][0]存的是他的父亲节点
    depth[u]=depth[fa]+1;//叶子结点的深度比父亲节点大一
    for(re int i=1;(1<<i)<=depth[u];++i)f[u][i]=f[f[u][i-1]][i-1];//往上跳（倍增思想）
    for(re int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v!=fa) dfs(v,u);
    }
}//建树
inline int lca(int u,int v)
{
    if(depth[u]<depth[v])swap(u,v);
    for(re int i=20;i>=0;--i)
    {
        if((1<<i)<=depth[u]-depth[v])
            u=f[u][i];
    }//u为深度较深的一点，先跳u使u，v达到同一深度
    if(u==v) return u;
    for(re int i=20;i>=0;--i)
    {
        if(f[u][i]!=f[v][i])
        {
            u=f[u][i];
            v=f[v][i];
        }
    }//达到同一深度后一起跳
    return f[u][0];
}
inline void Gmax(int u,int fa)
{
    for(re int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v!=fa)
        {
            Gmax(v,u);
            sum[u]+=sum[v];
        }
    }
    fnl=max(fnl,sum[u]);
}//用dfs来求以树为基础的查分数组的最大值
int main()
{
    freopen("D:\\算法进阶\\树链剖分\\in.txt","r",stdin);
    r(n),r(k);
    for(re int i=1,u,v;i<=n-1;++i)
    {
        r(u),r(v);
        add(u,v),add(v,u);
    }//建双向边
    dfs(1,0);
    while(k--)
    {
        //r(x),r(y);
        scanf("%d%d",&x,&y);
        int fa=lca(x,y);
        ++sum[x],++sum[y];
        --sum[fa],--sum[f[fa][0]];
    }//树上差分修改区间值
    Gmax(1,0);//求最值
    printf("%d",fnl);
}
