#include <iostream>
#include <cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=110;
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
            if(low[kid]>=num[u]&&u!=1)
                iscut[u]=1;

        }
         else if(num[kid]<num[u]&&kid!=fa)//有回退的边,一定是已经访问过的边
            {
                low[u]=min(num[kid],low[u]);
            }
    }
    if(u==1&&child>=2)
        iscut[1]=1;
}

int main()
{
    int ans=0,n;
    while(scanf("%d",&n)!=EOF&&n)
    {
        memset(low,0,sizeof(low));
        memset(num,0,sizeof(num));
        memset(iscut,0,sizeof(iscut));
        int t1,t2;
        char c;
        for(int i=0;i<=n;i++)
            v[i].clear();
        while(scanf("%d",&t1)!=EOF&&t1)
        {
            while(c=getchar()!='\n')
            {
                scanf("%d",&t2);
                v[t1].push_back(t2);
                v[t2].push_back(t1);
            }
        }
        cnt=0;
        ans=0;
        dfs(1,-1);
        for(int i=1;i<=n;i++)
        {
            ans+=iscut[i];
           //cout<<iscut[i]<<endl;
        }
        printf("%d\n",ans);

    }

    return 0;

}
