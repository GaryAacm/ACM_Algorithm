#include<bits/stdc++.h>
using namespace std;
const int maxn=6005;

int n,father[maxn],value[maxn];
vector<int> tree[maxn];
int a,b;
int dp[maxn][2];

void dfs(int t)
{
    dp[t][0]=0;//不选
    dp[t][1]=value[t];//选
    for(int i=0;i<tree[t].size();i++)//遍历子节点
    {
        int son=tree[t][i];//记录子节点
        dfs(son);//处理子节点
        dp[t][0]+=max(dp[son][0],dp[son][1]);
        dp[t][1]+=dp[son][0];
    }
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        {
            scanf("%d",&value[i]);
            father[i]=-1;//初始化为了后面辨别父亲节点
        }
        for(int i=1;i<n;i++)
        {
            scanf("%d%d",&a,&b);

            tree[b].push_back(a);//建树，记录父节点连接的子节点
            father[a]=b;
        }
        int t=1;
        while(father[t]!=-1)
        {
            t=father[t];//递归找到父节点
        }
        dfs(t);//从上往下找
        printf("%d\n",max(dp[t][1],dp[t][0]));
    return 0;
}

