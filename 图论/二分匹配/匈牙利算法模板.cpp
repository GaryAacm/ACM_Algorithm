#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
int u,v,t,n,m;
vector<int> e[maxn];
int vist[maxn],match[maxn];
bool dfs(int u,int tag)//tag用于标记找到目标，不同的人不一样
{
    if(vist[u]==tag) return false;
    vist[u]=tag;
    for(auto v:e[u])//以v去遍历e数组前u个
    {
        if(match[v]==0||dfs(match[v],tag))//未匹配或者上一个有其他的选择
        {
            match[v]=u;
            return true;
        }
    }
    return false;
}
int main()
{
    cin>>n>>m>>t;
    while(t--)
    {
        cin>>u>>v;
        e[u].push_back(v);//将所有的数据加入动态数组
    }
    int ans=0;
    for(int i=1;i<=n;++i)//遍历左部的男生
    {
        if(dfs(i,i))
        {
            ++ans;
        }
    }
    cout<<ans<<'\n';
    return 0;
}
