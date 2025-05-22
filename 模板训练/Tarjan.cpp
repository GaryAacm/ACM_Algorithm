#include<bits/stdc++.h>
using namespace std;
const int maxn=10005;
vector<int> G[maxn];
int cnt=0,dfn;
int low[maxn],top=0;//low是能够返回的最远祖先，num是节点访问顺序
int num[maxn],scnno[maxn],stacked[maxn];//scnno用来记录当前点属于哪个连通块

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
        else if(!scnno[v])//没有加进联通块
            low[u]=min(low[u],num[v]);

    }
    if(low[u]==num[u])//当前连通块的点的祖先
    {
        cnt++;
        while(1)
            {
                int v=stacked[--top];//出栈，表示同一个区间元素
                scnno[v]=cnt;
                if(u==v) break;//找到栈底的那个点
            }
    }
}

void Tarjan(int n)
{
    cnt=0;
    top=dfn=0;
    memset(num,0,sizeof(num));
    memset(scnno,0,sizeof(scnno));
    memset(low,0,sizeof(low));
    for(int i=1;i<=n;i++)
    {
        if(!num[i])
            dfs(i);
    }

}

int main()
{
    int n,m,u,v;
    while(scanf("%d%d",&n,&m),n!=0||m!=0)
    {
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
        printf("%s\n",cnt==1?"Yes":"No");

    }
    return 0;
}
