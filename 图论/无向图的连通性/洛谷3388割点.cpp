#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;//与poj那个不同，那个是以1为根节点，这里要所有的点遍历
vector<int> v[maxn];
int low[maxn],num[maxn],iscut[maxn];
int ssa[maxn];
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

            dfs(kid,fa);//递归最后一层
            if(u==fa) child++;
            low[u]=min(low[u],low[kid]);//更新子节点能够回退的点
            if(low[kid]>=num[u]&&u!=fa)//根节点单独处理（书上定理讲了，上面是非根节点的才处理）
                iscut[u]=1;

        }
         else //有回退的边,一定是已经访问过的边(这里的割点和割边求法不同)!!!
            {
                low[u]=min(num[kid],low[u]);
            }
        /*if(num[kid]&&kid!=fa)
		{
			//if(kid==fa&&!vis)vis=true;//判断重复边
             low[u]=min(low[u],num[kid]);
		}*/
    }
    if(u==fa&&child>=2)//单独处理根节点
        iscut[u]=1;
}
int n,m;
int main()
{

    //freopen("D:\\算法进阶\\图论\\P3388_1.in","r",stdin);
    //freopen("123.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=1;i<=n;i++)
    {
        if(!num[i])
           dfs(i,i);
    }

    int ans=0;

    for(int i=1;i<=n;i++)
    {
        ans+=iscut[i];


    }
    printf("%d\n",ans);
    for(int i=1;i<=n;i++)
    {

        if(iscut[i])
            printf("%d ",i);
    }

    return 0;
}
