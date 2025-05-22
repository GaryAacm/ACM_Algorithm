/*这里注意就是建好新图之后，利用拓扑排序（注意拓扑排序的节点顺序直接在拓扑排序里面dp）
然后就是dp是利用了当前节点的最优解是由上一节点转化而来，利用拓扑的顺序来指定dp顺序*/
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
int dp[maxn];
int in[maxn],vis[maxn],val[maxn];

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
                //cout<<"连通块："<<cnt<<"含有："<<v<<endl;
                countt[cnt]+=val[v];
                //记录这一块全部点的权值
                if(u==v)
                {
                    break;
                }
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

queue<int>Q;

void tuopu()
{
    for(int i=1;i<=cnt;i++)
    {
        if(in[i]==0)
        {
            Q.push(i);
            dp[i]=countt[i];
        }
   }
    while(!Q.empty())
    {
        int u=Q.front();
        //cout<<"当前联通量："<<u<<endl;
        Q.pop();
        for(int i=0;i<GG[u].size();i++)
        {
            int v=GG[u][i];
            //cout<<"对应的点："<<v<<endl;
            dp[v]=max(dp[v],dp[u]+countt[v]);
            in[v]--;
            if(!in[v])
            {
                Q.push(v);
                //cout<<"入队"<<v<<endl;
            }
        }
    }
}

void solve()
{
    //处理入度
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<G[i].size();j++)
        {
            if(scnno[i]!=scnno[G[i][j]])
            {
                in[scnno[G[i][j]]]++;
                GG[scnno[i]].push_back(scnno[G[i][j]]);
                //cout<<scnno[i]<<" 通向："<<scnno[G[i][j]]<<endl;

            }
        }
    }
    //for(int i=1;i<=cnt;i++) cout<<"当前联通块："<<i<<" 入度："<<in[i]<<"权值："<<countt[i]<<endl;
    tuopu();

    int ans=-1;
    for(int i=1;i<=cnt;i++)
    {
        ans=max(ans,dp[i]);
    }
    printf("%d\n",ans);
}


int main()
{

    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
        scanf("%d",&val[i]);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
    }
    Tarjan(n);

    solve();
    return 0;
}

