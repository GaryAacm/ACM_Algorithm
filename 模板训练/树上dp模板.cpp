#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=10005;

//通用的dfs模板，都会递归到最底层处理完子节点然后处理父节点
/*void dfs(int v) { // 遍历节点v
	dp[v] = ...; // 初始化
	for(int u: G[v]) { // 遍历v的所有子节点
		dfs(u);
		update(u, v); // 用子节点的dp值对当前节点的dp值进行更新
	}
}
*/

//求子树大小

/*#include <cstdio>
#include <vector>
#define maxn 100
using namespace std;

vector<int> G[maxn]; // 邻接表
int sz[maxn]; // dp数组，sz[v] = 子树v的大小

void dfs(int v)
{
	sz[v] = 1; // 初始化，最初大小为1，后面累加
	for(int i=0;i<G[v].size();i++) // 遍历子结点
	{
        int u=G[v][i];
		dfs(u); // 先对子结点进行dfs
		sz[v] += sz[u]; // 更新当前子树的大小
	}
}

int main()
{
	int n;
	scanf("%d", &n); // 结点个数
	for(int i=1; i<n; i++) // N-1条边
	{
		int u, v;
		scanf("%d%d", &u, &v); // 读入一条边
		G[u].push_back(v); // 存入邻接表
	}
	dfs(1);
	for(int i=1; i<=n; i++)
		printf("%d\n", sz[i]);
	return 0;
}
*/

//经典没有上司的舞会
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

signed main()
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
