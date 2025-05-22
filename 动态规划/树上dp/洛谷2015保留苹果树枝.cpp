#include<bits/stdc++.h>
using namespace std;
const int maxn=110;
vector<int> tree[maxn];
int n,q;
int a,b,temp;
int value[maxn][maxn],vis[maxn];
int dp[maxn][maxn];//表示到了第i个节点的时候保留下来了j根树枝
void dfs(int father)
{
    vis[father]=1;//防止重复访问
    for(int i=0;i<tree[father].size();i++)
    {
        int son=tree[father][i];

        if(vis[son]==1) continue;//重复找，说明是父节点
        dfs(son);//树上dp核心，递归处理

        for(int j=q;j>=1;j--)//枚举留下来的
        {
            for(int k=0;k<j;k++)//枚举的时候保留一根到父节点
                {
                    dp[father][j]=max(dp[father][j],value[father][son]+dp[son][k]+dp[father][j-k-1]);//算上当前根，还有son保留的，剩下的是父亲保留的
                }
        }
    }

}

int main()
{
    cin>>n>>q;
    for(int i=1;i<n;i++)
    {
        cin>>a>>b>>temp;
        tree[a].push_back(b);
        tree[b].push_back(a);
        value[a][b]=value[b][a]=temp;
        //双向存边，解决不知道边哪个是父亲节点的问题
    }

    dfs(1);
    cout<<dp[1][q]<<endl;

    return 0;
}

