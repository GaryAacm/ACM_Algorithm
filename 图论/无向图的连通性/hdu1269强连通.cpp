#include<bits/stdc++.h>
using namespace std;
const int maxn=10005;
vector<int> G[maxn],rG[maxn];
int cnt=0;
vector<int> s;
int vis[maxn],scnno[maxn];

void dfs1(int u)
{
    if(vis[u]) return ;
    vis[u]=1;
    for(int i=0;i<G[u].size();i++)
    {
        dfs1(G[u][i]);
    }
    s.push_back(u);//按照遍历顺序从小到大，即最后的放在第一位
}

void dfs2(int u)
{
    if(scnno[u]) return ;
    scnno[u]=cnt;
    for(int i=0;i<rG[u].size();i++)
    {
        dfs2(rG[u][i]);
    }
}

void kosaraju(int n)
{
    cnt=0;
    s.clear();
    memset(vis,0,sizeof(vis));
    memset(scnno,0,sizeof(scnno));
    for(int i=1;i<=n;i++) dfs1(i);
    for(int i=n-1;i>=0;i--)//从最后的点开始
    {
        if(!scnno[s[i]])
        {
            cnt++;
            dfs2(s[i]);//找相连的点
        }
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
            rG[i].clear();
        }
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&u,&v);
            G[u].push_back(v);//原图
            rG[v].push_back(u);//反图
        }
        kosaraju(n);
        printf("%s\n",cnt==1?"Yes":"No");
        //printf("%d\n",cnt);

    }

    return 0;
}

