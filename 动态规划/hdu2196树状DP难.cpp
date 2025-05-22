#include<bits/stdc++.h>
using namespace std;
const int maxn=10010;
struct node
{
    int id;
    int cost;
};
vector<node> tree[maxn];
int dp[maxn][3];//0表示子节点到本身的最大距离，1表示次最大距离，2表示往上走找父节点的最大距离
int n;

void dfs1(int u)//找0和1
{
    int one=0,two=0;
    for(int i=0;i<tree[u].size();i++)
    {
        node son=tree[u][i];
        dfs1(son.id);//从下往上递归
        int cost= son.cost+dp[son.id][0];
        if(cost>=one)
        {
            two=one;
            one=cost;//记录最大和第二大的数
        }
        if(cost>two&&one>cost)
            two=cost;//更新第二小
    }
    dp[u][0]=one;
    dp[u][1]=two;
}

void dfs2(int u)//找2
{
    for(int i=0;i<tree[u].size();i++)
    {
        node son=tree[u][i];
        if(dp[son.id][0]+son.cost==dp[u][0])//在最大子树上,搜次最长和往上走的
        {
            dp[son.id][2]=max(dp[u][2],dp[u][1])+son.cost;
        }
        else
            dp[son.id][2]=max(dp[u][2],dp[u][0])+son.cost;//不在最大子树上，搜最长和往上走的，注意更新的是子节点
        dfs2(son.id);//因为是子节点逐步更新的，所以在最后搜
    }
}

int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++)
            tree[i].clear();
        memset(dp,0,sizeof(dp));
        for(int i=2;i<=n;i++)
        {
            node temp;
            int x,y;
            scanf("%d%d",&x,&y);
            temp.id=i;
            temp.cost=y;
            tree[x].push_back(temp);
        }
        dfs1(1);
        dp[1][2]=0;
        dfs2(1);
        for(int i=1;i<=n;i++)
            printf("%d\n",max(dp[i][0],dp[i][2]));//子节点或者往上走

    }
    return 0;
}
