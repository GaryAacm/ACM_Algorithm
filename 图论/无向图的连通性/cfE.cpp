#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>

const int N=300005,M=600005;

int n,m,head[N],dis[N],from[N];
int cnt,cir_cnt,dfn[N],low[N],cir[N];
int _head[N],_dis[N];

struct Edge
{
    int from,next,to;
};
Edge E[M],_E[M];
bool vis[M];

void add(int u,int v)
{
    static int tot=0;
    E[++tot].next=head[u];
    E[tot].to=v;
    head[u]=tot;
}
void _add(int u,int v)
{
    static int tot=0;
    _E[++tot].next=_head[u];
    _E[tot].from=u;
    _E[tot].to=v;
    _head[u]=tot;
}

void tarjan(int u,int fa)
{
    static std::stack<int> s;
    low[u]=dfn[u]=++cnt;
    s.push(u);
    for(int i=head[u];i;i=E[i].next)
    {
    	int v=E[i].to;
        if(v==fa)continue;
        if(!dfn[v])
        {
            tarjan(v,u);
            low[u]=std::min(low[u],low[v]);
        }
        else
        {
            if(cir[v]==0)low[u]=std::min(low[u],dfn[v]);
        }
    }
    if(low[u]!=dfn[u])return;
    cir_cnt++;
    while(1)
    {
        int x=s.top();
        s.pop();
        cir[x]=cir_cnt;
        if (x==u)break;
    }
}

int bfs(int s)
{
    int res=s;
    memset(dis,0x3f,sizeof(dis));
    std::queue<int> q;
    q.push(s);
    dis[s]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=head[u];i;i=E[i].next)
        {
            int v=E[i].to;
            if(dis[v]!=0x3f3f3f3f)continue;
            dis[v]=dis[u]+1;
            q.push(v);
            if(dis[v]>dis[res])res=v;
        }
    }
    return res;
}

int _bfs(int s)
{
    int res=s;
    memset(_dis,0x3f,sizeof(_dis));
    std::queue<int> q;
    q.push(s);
    _dis[s]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=_head[u];i;i=_E[i].next)
        {
            int v=_E[i].to;
            if(_dis[v]!=0x3f3f3f3f)continue;
            _dis[v]=_dis[u]+1;
            q.push(v);
            if(_dis[v]>_dis[res])res=v;
        }
    }
    return res;
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;++i)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        add(u,v);
        add(v,u);
    }
    tarjan(1,0);
    for(int u=1;u<=n;++u)
    {
        for(int i=head[u];i;i=E[i].next)
        {
            int v=E[i].to;
            if(cir[u]!=cir[v])
            {
                _add(cir[u],cir[v]);
            }
        }
    }
    int s=_bfs(cir[1]);
    s=_bfs(s);
    printf("%d",_dis[s]);
}

