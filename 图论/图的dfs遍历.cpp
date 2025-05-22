#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int vis[maxn];
vector<int> v[maxn];

void dfs(int u)
{
    if(vis[u]) return ;
    vis[u]=1;

    for(int i=0;i<v[u].size();i++)
    {
        if(!vis[v[u][i]])
        {
            cout<<v[u][i]<<endl;
            dfs(v[u][i]);
        }
    }
}

int main()
{
    for(int i=0;i<7;i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    //cout<<"1"<<endl;

    //dfs(1);
    for(int i=1;i<=6;i++)
    {
        dfs(i);
    }

    return 0;
}
