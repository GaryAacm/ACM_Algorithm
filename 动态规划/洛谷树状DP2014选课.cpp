#include<bits/stdc++.h>
using namespace std;

const int maxn=305;

int value[maxn];
vector<int> tree[maxn];
int n,m;
int dp[maxn][maxn];//i为根节点，选了j节课

void dfs(int father)
{
    dp[father][1]=value[father];
    dp[father][0]=0;
    for(int i=0;i<tree[father].size();i++)
    {
        int son=tree[father][i];
        dfs(son);//每次递归更新子节点的值

        for(int j=m+1;j>=1;j--)//枚举体积
        {
            for(int k=0;k<j;k++)//枚举组内物品
            {
                dp[father][j]=max(dp[father][j],dp[son][k]+dp[father][j-k]);//必须选父亲的那件，所以不能k取到j
            }
        }
    }
}

int main()
{
    cin>>n>>m;
    value[0]=0;
    memset(dp,0xcf,sizeof(dp));//初始化负无穷

    for(int i=1;i<=n;i++)
    {
       int s,k;
        cin>>k>>s;
        value[i]=s;//记录对应的学分
       tree[k].push_back(i);
    }
    dfs(0);//用0来统一所有的数据,作为根节点
    cout<<dp[0][m+1]<<endl;
    return 0;
}
