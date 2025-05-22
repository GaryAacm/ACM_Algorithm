#include <iostream>
#include <cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=1050;
vector<int> v[maxn];
int low[maxn],num[maxn],iscut[maxn];
int cnt=0;
void dfs(int u,int fa)
{
    low[u]=num[u]=++cnt;//更新初始值
    int child=0;
    for(int i=0;i<v[u].size();i++)
    {
        int kid=v[u][i];
        if(!num[kid])//子节点没有访问过,可以继续更新
        {
            child++;
            dfs(kid,u);//递归最后一层
            low[u]=min(low[u],low[kid]);//更新子节点能够回退的点
            if(low[kid]>=num[u]&&u!=0)
                iscut[u]++;

        }
         else if(num[kid]<num[u]&&kid!=fa)//有回退的边,一定是已经访问过的边
            {
                low[u]=min(num[kid],low[u]);
            }
    }
    if(u==0&&child>=2)
        iscut[0]++;
}
int n,m;
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(low,0,sizeof(low));
        memset(num,0,sizeof(num));
        memset(iscut,0,sizeof(iscut));
        for(int i=0;i<=n;i++)
            v[i].clear();
        for(int i=1;i<=m;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            v[a].push_back(b);
            v[b].push_back(a);
        }
    }
    cnt=0;
    dfs(0,0);
    int ans=0;
    for(int i=0;i<n;i++)
        ans+=iscut[i];
    printf("%d\n",ans);

    return 0;

}
