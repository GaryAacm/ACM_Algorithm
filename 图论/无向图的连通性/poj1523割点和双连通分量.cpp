#include <iostream>
#include <cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=1010;
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
                iscut[u]++;//两个点的连通分量就只加一次，多个点就加上多次，每个割点删除之后，两端的点就联通不了，就会产生几个分块
            if(u==1&&child>1)
                iscut[1]++;

        }
         else if(num[kid]<num[u]&&kid!=fa)//有回退的边,一定是已经访问过的边
            {
                low[u]=min(num[kid],low[u]);
            }
    }

}
int netorder=0;
int main()
{
   int ans=0,n=0;
   int t1,t2;
    while(scanf("%d",&t1)!=EOF&&t1)
    {
        memset(low,0,sizeof(low));
        memset(num,0,sizeof(num));
        for(int i=0;i<=maxn;i++)
            iscut[i]=1;

        char c;
        for(int i=0;i<=maxn;i++)
            v[i].clear();
        n=t1;
        scanf("%d",&t2);
        n=max(n,t2);
        v[t1].push_back(t2);
        v[t2].push_back(t1);
        while(scanf("%d",&t1)!=EOF&&t1)
        {
            scanf("%d",&t2);
            n=max(n,t2);
            n=max(t1,n);
            v[t1].push_back(t2);
            v[t2].push_back(t1);
        }
        cnt=0;
        ans=0;
        dfs(1,-1);
        printf("Network #%d\n",++netorder);
        int flag=0;
        for(int i=1;i<=n;i++)
        {
            //cout<<iscut[i]<<endl;
            if(iscut[i]>1)
            {
                printf("  SPF node %d leaves %d subnets\n",i,iscut[i]);
                flag=1;
            }
        }
        if(flag==0)
            printf("  No SPF nodes\n");
        printf("\n");
    }

    return 0;

}
