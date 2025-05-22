#include<bits/stdc++.h>
using namespace std;
const int maxn=5e4+10;
vector<int> G[maxn];
int cnt=0,dfn,ord=0,ans=0;
int low[maxn],top=0;//low是能够返回的最远祖先，num是节点访问顺序
int num[maxn],scnno[maxn],stacked[maxn];

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
        ord=0;
        bool flag=true;
        cnt++;
        while(1)
            {
                int v=stacked[--top];//出栈，表示同一个区间元素
                scnno[v]=cnt;
                ord++;
                if(ord>=2&&flag)
                {
                    ans++;
                    flag=false;
                }
                if(u==v) break;//找到另外一个的祖先
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

int main()
{
    int n,m,u,v;
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
    printf("%d\n",ans);
    return 0;
}

