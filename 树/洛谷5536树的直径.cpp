#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;

struct Edge
{
	int next;  //上一个同起点的边的序号
	int to;  //这条边指向的点
	int w;  //这条边的长度
};

Edge edge[maxn*2];

int head[maxn];

int cnt = 1;

void add(int u, int v, int w)
{
    edge[cnt].w = w;
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}

//----------------------上面是建立边----------------------


int deep[maxn],maxdeep[maxn],mid,temp=0,num,path[maxn],ans[maxn];
int n,k,u,v;
bool cmp(int a,int b)
{
    return a>b;
}

//-----------第一次搜索,找最长的端点----------
void dfs1(int u,int fa)
{
    if(deep[u]>temp)
    {
        num=u;//记录下最远端直径端点
        temp=deep[u];
    }
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        int wei=edge[i].w;
        if(v==fa) continue;

        deep[v]=deep[u]+1;
        dfs1(v,u);
    }
}

//------------------再用上次的点做一次dfs，回到原来的端点，记录路径--------------
void dfs2(int u,int fa)
{
    if(deep[u]>temp)
    {

        temp=deep[u];
        num=u;
    }
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        int wei=edge[i].w;
        if(v==fa) continue;

        deep[v]=deep[u]+1;
        path[v]=u;//记录父节点
        dfs2(v,u);
    }
}

//----------------从中点开始找深度-----------------------
void dfs_mid(int u,int fa)
{
    maxdeep[u]=deep[u];//当前深度
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        int wei=edge[i].w;
        if(v==fa) continue;
        deep[v]=deep[u]+1;
        dfs_mid(v,u);
        maxdeep[u]=max(maxdeep[u],maxdeep[v]);//更新最终的深度,表示这个点可以到达的最深的深度
    }
}

int main()
{
    //freopen("D:\\算法进阶\\树\\in.txt","r",stdin);
    scanf("%d%d",&n,&k);
    for(int i=1;i<n;i++)
    {
        scanf("%d%d",&u,&v);
        add(u,v,1);
        add(v,u,1);
    }
    //temp=0;
    //memset(deep,0,sizeof(deep));
    dfs1(1,0);

    temp=0;
    memset(deep,0,sizeof(deep));
    dfs2(num,0);

//----------------找到直径的中点------------------
    int mid=num;//中点要初始化！！！
    for(int i=1;i<=(deep[num]+1)/2;++i) mid=path[mid];//找到中点

    memset(deep,0,sizeof(deep));
    dfs_mid(mid,0);

    for(int i=1;i<=n;++i)
    {
        ans[i]=maxdeep[i]-deep[i];
    }
    sort(ans+1,ans+1+n,cmp);//从大到小
    int ans_end=0;
    for(int i=k+1;i<=n;++i) ans_end=max(ans_end,ans[i]+1);//因为起始深度是0

    printf("%d\n",ans_end);

    return 0;

}
