
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
//f[i][j]��ʾ��iΪ���������2^j���㣬depth��ʾ��ȣ�sumΪǰ׺������
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
    f[u][0]=fa;//2^0=1,����f[u][0]��������ĸ��׽ڵ�
    depth[u]=depth[fa]+1;//Ҷ�ӽ�����ȱȸ��׽ڵ��һ
    for(re int i=1;(1<<i)<=depth[u];++i)f[u][i]=f[f[u][i-1]][i-1];//������������˼�룩
    for(re int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v!=fa) dfs(v,u);
    }
}//����
inline int lca(int u,int v)
{
    if(depth[u]<depth[v])swap(u,v);
    for(re int i=20;i>=0;--i)
    {
        if((1<<i)<=depth[u]-depth[v])
            u=f[u][i];
    }//uΪ��Ƚ����һ�㣬����uʹu��v�ﵽͬһ���
    if(u==v) return u;
    for(re int i=20;i>=0;--i)
    {
        if(f[u][i]!=f[v][i])
        {
            u=f[u][i];
            v=f[v][i];
        }
    }//�ﵽͬһ��Ⱥ�һ����
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
}//��dfs��������Ϊ�����Ĳ����������ֵ
int main()
{
    freopen("D:\\�㷨����\\�����ʷ�\\in.txt","r",stdin);
    r(n),r(k);
    for(re int i=1,u,v;i<=n-1;++i)
    {
        r(u),r(v);
        add(u,v),add(v,u);
    }//��˫���
    dfs(1,0);
    while(k--)
    {
        //r(x),r(y);
        scanf("%d%d",&x,&y);
        int fa=lca(x,y);
        ++sum[x],++sum[y];
        --sum[fa],--sum[f[fa][0]];
    }//���ϲ���޸�����ֵ
    Gmax(1,0);//����ֵ
    printf("%d",fnl);
}
