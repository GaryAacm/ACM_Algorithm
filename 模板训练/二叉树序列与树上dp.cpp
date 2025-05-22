#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=500005;
char s[maxn];
int tree[maxn][2],dp[maxn][2],tot=0,root=1;

void dfs(int root)//二叉树子序列建树
{
    tot++;
    if(s[root]=='0') return ;
    else if(s[root]=='1')
    {
        tree[root][0]=root+1;
        dfs(root+1);
    }
    else
    {
        tree[root][0]=root+1;
        dfs(root+1);
        tree[root][1]=tot+1;//右子树一定是这个节点
        dfs(tot+1);
    }
}

//染色问题都分为此点染不染色来判断
signed main()
{
    scanf("%s",s+1);
    int n=strlen(s+1);
    dfs(root);
    for(int i=n;i>=1;i--)//从子节点开始
    {
        dp[i][1]=dp[tree[i][0]][0]+dp[tree[i][1]][0]+1;
        dp[i][0]=max(dp[tree[i][0]][1]+dp[tree[i][1]][0],dp[tree[i][0]][0]+dp[tree[i][1]][1]);
    }
    printf("%lld ",max(dp[1][1],dp[1][0]));//最后我们只要比较一下，树根染和不染的答案哪个更优
    for (int i=n;i>=1;i--)
    {
        dp[i][1]=dp[tree[i][0]][0]+dp[tree[i][1]][0]+1;
        dp[i][0]=min(dp[tree[i][0]][1]+dp[tree[i][1]][0],dp[tree[i][0]][0]+dp[tree[i][1]][1]);
    }
    printf("%lld",min(dp[1][1],dp[1][0]));
    return 0;
}

