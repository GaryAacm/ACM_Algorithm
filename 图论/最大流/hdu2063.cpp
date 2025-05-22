#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
int u,v,t,n,m;
vector<int> e[maxn];
int vist[maxn],match[maxn];
bool dfs(const int u,const int tag)//tag用于标记找到目标，不同的人不一样
{
    if(vist[u]==tag) return false;//表示已经有人选过了
    vist[u]=tag;
    for(auto v:e[u])//以v去遍历e数组前u个
    {
        if(match[v]==0||dfs(match[v],tag))//未匹配或者上一个有其他的选择，改选也在里面
        {
            match[v]=u;
            return true;
        }
    }
    return false;
}
int main()
{

    //freopen("D:\\算法进阶\\图论\\最大流\\in.txt","r",stdin);
    while(scanf("%d",&t)!=EOF&&t)
    {

        scanf("%d%d",&n,&m);
        memset(match,0,sizeof(match));
        memset(vist,0,sizeof(vist));
        for(int i=0;i<=n;i++) e[i].clear();
    for(int i=0;i<t;i++)
    {
        scanf("%d%d",&u,&v);
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
    printf("%d\n",ans);
    }

    return 0;
}
