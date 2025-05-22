#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#include<stack>
using namespace std;
const int maxn=5000+10;
int n,m,q;
vector<int> G[maxn], bcc[maxn];
int dfs_clock,bcc_cnt;
int pre[maxn],low[maxn],bccno[maxn];
vector<int> belong[maxn];//belong[i]表示第i个节点属于的所有点双连通分量编号
struct Edge
{
    int u,v;
    Edge(int u,int v):u(u),v(v){}
};
stack<Edge> S;
void dfs(int u,int fa)
{
    low[u]=pre[u]=++dfs_clock;
    for(int i=0;i<G[u].size();i++)
    {
        int v=G[u][i];
        if(v==fa) continue;
        Edge e=Edge(u,v);
        if(!pre[v])
        {
            S.push(e);
            dfs(v,u);
            low[u]=min(low[v],low[u]);
            if(low[v]>=pre[u])//割顶
            {
                bcc_cnt++; bcc[bcc_cnt].clear();
                while(true)
                {
                    Edge x=S.top(); S.pop();
                    if(bccno[x.u]!=bcc_cnt)
                    {
                        bcc[bcc_cnt].push_back(x.u), bccno[x.u]=bcc_cnt;
                        belong[x.u].push_back(bcc_cnt);
                    }
                    if(bccno[x.v]!=bcc_cnt)
                    {
                        bcc[bcc_cnt].push_back(x.v), bccno[x.v]=bcc_cnt;
                        belong[x.v].push_back(bcc_cnt);
                    }
                    if(x.u==u && x.v==v) break;
                }
            }
        }
        else if(pre[v]<pre[u])
        {
            S.push(e);
            low[u]=min(low[u],pre[v]);
        }
    }
}
int fa[maxn];
int find(int i)
{
    if(fa[i]==-1) return i;
    return fa[i]=find(fa[i]);
}
int main()
{
    int kase=0;
    while(scanf("%d%d%d",&n,&m,&q)==3&&n)
    {
        bcc_cnt=dfs_clock=0;
        memset(pre,0,sizeof(pre));
        memset(bccno,0,sizeof(bccno));
        memset(fa,-1,sizeof(fa));
        for(int i=0;i<n;i++) G[i].clear(),belong[i].clear();
        while(m--)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            G[u].push_back(v);
            G[v].push_back(u);
            u=find(u), v=find(v);
            if(u!=v) fa[u]=v;
        }
        for(int i=0;i<n;i++)
            if(!pre[i]) dfs(i,-1);
        printf("Case %d:\n",++kase);
        while(q--)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            if(find(u)!=find(v)) printf("zero\n");
            else
            {
                bool flag=false;
                //u点与v点所属的点双连通分量集合有交集,注意可能交集数<=1
                //以上结论可以分情况证明出来,注意两个割点的分量交集数<=1
                for(int i=0;i<belong[u].size()&&!flag;i++)
                for(int j=0;j<belong[v].size()&&!flag;j++)
                {
                    if(belong[u][i]==belong[v][j])
                    {
                        int num=belong[u][i];
                        if(bcc[num].size()>2)
                            printf("two or more\n"),flag=true;
                    }
                }
                if(!flag) printf("one\n");
            }
        }
    }
    return 0;
}
