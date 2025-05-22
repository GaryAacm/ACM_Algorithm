/*处理的一个思路，用算法里面实现的记录连通块的属于那一块，考虑到不同连通块之间有不同的连接路径*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=5e4+10;
vector<int> G[maxn];
vector<int> GG[maxn];
int cnt=0,dfn,ans=0,ord=1,now;
int n,m,u,v;
int low[maxn],top=0;//low是能够返回的最远祖先，num是节点访问顺序
int num[maxn],scnno[maxn],stacked[maxn];
int countt[maxn];

int out[maxn],vis[maxn];

void dfs(int u)
{
    num[u]=low[u]=++dfn;//第一个点作为访问顺序
    stacked[top++]=u;

    for(int i=0;i<G[u].size();i++)
    {
        int v=G[u][i];
        if(!num[v])
        {
            dfs(v);
            low[u]=min(low[u],low[v]);//往上更新回退边
        }
        else if(!scnno[v])
            low[u]=min(low[u],num[v]);//处理回退边,其实就是处理子节点小于父节点的情况

    }
    if(low[u]==num[u])//代表祖先
    {
        cnt++;
        while(1)
            {
                int v=stacked[--top];//出栈，表示同一个区间元素
                scnno[v]=cnt;//记录属于那一块连通区域
                countt[cnt]++;//记录这一块有多少个点
                if(u==v)
                {
                    break;
                }
                //找到另外一个的祖先
            }

    }
}

void Tarjan(int n)
{
    cnt=0;
    top=dfn=0;
    memset(num,0,sizeof(num));
    memset(scnno,0,sizeof(scnno));
    memset(low,0,sizeof(num));
    for(int i=1;i<=n;i++)
    {
        if(!num[i])
            dfs(i);
    }
}
void solve()
{
    int num2=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<G[i].size();j++)
        {
            if(scnno[i]!=scnno[G[i][j]])//用此来比较联通的是否同一块
            {
                out[scnno[i]]++;//不是就加上出度，用的是这一块的标记

            }
        }
    }
    for(int i=1;i<=cnt;i++)
    {
        if(!out[i]) num2++,ans=countt[i];
    }

    if(num2>1) printf("0\n");
    else printf("%d\n",ans);
}

int main()
{

    scanf("%d%d",&n,&m);
    for(int i=0;i<=n;i++)
    {
        G[i].clear();
    }
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
    }
    Tarjan(n);

    solve();
    return 0;
}
