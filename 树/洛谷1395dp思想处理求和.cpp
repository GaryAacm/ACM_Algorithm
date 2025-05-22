#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
typedef long long ll;

struct Edge  //每一个edge代表一条边，数组序号代表编号
{
	int next;  //上一个同起点的边的序号
	int to;  //这条边指向的点
	int w;  //这条边的长度
};

Edge edge[maxn*2];  //建立反向边,开两倍数组记得！！！

int head[101];  //head[i],代表以i为起点的边的最大序号是head[i]，随着数组的输入而更新

int cnt = 1;   //工具变量，记录边的序号，顺便(真的是顺便，这个功能非必要)记录了有几条边，add函数用一次自加一次

void add(int u, int v, int w)  //输入从u到v的长度为w的边
{
    edge[cnt].w = w;  //第cnt条边长为w
    edge[cnt].to = v;  //第cnt条边指向点v
    edge[cnt].next = head[u];  //上一条以u为起点的最大序号的边的序号是head[u]，每一条边都记录下了上一个同起点的边的序号，用next
    head[u] = cnt++;  //现在以u为起点的最大序号的边的序号是cnt了
}

int n,a,b;
ll dp[maxn],Size[maxn],d[maxn];
int vist[maxn];

void dfs1(int u,int fa)
{
    Size[u]=1;
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(d[v]) continue;//找过了
        d[v]=d[u]+1;
        dfs1(v,u);
        Size[u]+=Size[v];
    }
}

void dfs2(int u,int fa)//更新节点
{
    dp[u]=dp[fa]+n-2*Size[u];
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==fa) continue;

        dfs2(v,u);

    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    //freopen("D:\\算法进阶\\树\\in.txt","r",stdin);

    cin>>n;
    for(int i=1;i<n;i++)
    {
        cin>>a>>b;
        add(a,b,1);
        add(b,a,1);

    }
    d[1]=1;
    dfs1(1,0);
    ll maxnn=0;
    int idx;
    for(int i=1;i<=n;i++)
        maxnn+=d[i];//求出根节点的深度
    maxnn-=n;
    //cout<<maxnn<<endl;
    dp[1]=maxnn;
    for(int i=head[1];i;i=edge[i].next)//更新dp
    {
        int v=edge[i].to;
        dfs2(v,1);
    }
    for(int i=2;i<=n;i++)
    {
        if(maxnn>dp[i])
        {
            maxnn=dp[i];
            idx=i;
        }
    }

    cout<<idx<<' '<<maxnn<<endl;

    return 0;

}
