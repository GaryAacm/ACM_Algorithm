#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;

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


ll deep[maxn],maxdeep[maxn],mid,temp=0,num,path[maxn],ans[maxn],realdeep[maxn],deep2[maxn];
int n,k,u,v,w;
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

        deep[v]=deep[u]+wei;

        dfs1(v,u);
    }
}

//------------------再用上次的点做一次dfs，找到另外一端的最值，记录路径--------------
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

        deep[v]=deep[u]+wei;
        path[v]=u;//记录父节点
        dfs2(v,u);
    }
}


void dfs3(int u,int fa)
{
    if(deep2[u]>temp)
    {

        temp=deep2[u];
        //num=u;
    }
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        int wei=edge[i].w;
        if(v==fa) continue;

        deep2[v]=deep2[u]+wei;


        dfs3(v,u);
    }
}



int main()
{
    //freopen("D:\\算法进阶\\树\\树的直径\\input.txt","r",stdin);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=k;i++)
    {
        scanf("%d%d%d",&u,&v,&w);
        add(u,v,w);
        add(v,u,w);
    }

    dfs1(1,0);
    int start=num;

    temp=0;
    memset(deep,0,sizeof(deep));
    dfs2(num,0);
    int ed=num;
    ll ans_end=0,temp1=0;
    ans_end=deep[ed];//最长的直径的距离
    //cout<<ans_end<<endl;
    //cout<<start<<' '<<ed<<endl;

    memset(deep,0,sizeof(deep));
    //dfs1(start,0);
    dfs1(ed,0);

    memset(deep2,0,sizeof(deep2));
    dfs3(start,0);


   for(int i=1;i<=n;++i)
   {
      ll d=min(deep[i],deep2[i]);
      if(d>temp1) temp1=d;

   }

    printf("%lld",ans_end+temp1);
    return 0;

}


