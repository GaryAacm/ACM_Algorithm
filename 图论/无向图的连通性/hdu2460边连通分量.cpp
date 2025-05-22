#include <iostream>
#include <cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=1010;
int low[maxn],cnt;
vector<int> v[maxn];
int n,m;

void dfs(int u,int fa)
{
    low[u]=++cnt;
    for(int i=0;i<v[u].size();i++)
    {
        int kid=v[u][i];
        if(kid==fa) continue;
        if(!low[kid])
        {
            dfs(kid,u);
        }
        low[u]=min(low[u],low[kid]);//更新联通的点，找最小的作为代表
    }

}

int Tarjan()
{
    int deg[maxn];
    memset(deg,0,sizeof(deg));
    //for(int i=1;i<=n;i++)
        //cout<<low[i]<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<v[i].size();j++)
        {
            if(low[v[i][j]]!=low[i])
            {
                deg[low[i]]++;//相同的点看成一块，不相同的++

            }
        }
    }
    int res=0;
    for(int i=1;i<=n;i++)
    {
        if(deg[i]>0)
        {
             res++;
             cout<<deg[i]<<endl;
        }

    }

    return res;
}
int q;
int main()
{
    int order=0;
    while(scanf("%d%d",&n,&m)&&(n&&m))
    {
        int a,b;
        memset(low,0,sizeof(low));
        for(int i=0;i<=n;i++) v[i].clear();
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&a,&b);
            v[a].push_back(b);
            v[b].push_back(a);
        }
        scanf("%d",&q);
        printf("Case %d:\n",++order);
        while(q--)
        {
            scanf("%d%d",&a,&b);
            v[a].push_back(b);
            v[b].push_back(a);
            dfs(1,-1);
            int ans=Tarjan();

            printf("%d\n",ans);
        }
    }
    return 0;
}
