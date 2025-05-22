#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+10;

int num[maxn],low[maxn],dfn=0,judge[maxn];
vector<int> s[maxn];
int n,m,u,v;

void dfs(int u,int fa)
{
    num[u]=low[u]=++dfn;
    int child=0;
    for(int i=0;i<s[u].size();i++)
    {
        int v=s[u][i];

        if(!num[v])
        {
            child++;
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            if(num[u]<=low[v]&&u!=fa)//处理多图不连通
            {
                judge[u]=1;
            }
        }
        else if(num[u]>num[v]&&v!=fa)
        {
            low[u]=min(low[u],num[v]);
        }
    }
    if(child>=2&&u==fa)//处理不连通的情况
    {
        judge[u]=1;
    }
    return ;
}

signed main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v;
        s[u].push_back(v);
        s[v].push_back(u);
    }
    dfn=0;
    for(int i=1;i<=n;i++)
    {
        if(!num[i])
        {
            dfs(i,i);

        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(judge[i]) ans++;
    }
    cout<<ans<<endl;

    for(int i=1;i<=n;i++)
    {
        if(judge[i]) cout<<i<<' ';
    }

}
