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

Edge edge[maxn*2],edgereverse[maxn*2];  //建立反向边,开两倍数组记得！！！

int head[101];  //head[i],代表以i为起点的边的最大序号是head[i]，随着数组的输入而更新

int cnt = 1;   //工具变量，记录边的序号，顺便(真的是顺便，这个功能非必要)记录了有几条边，add函数用一次自加一次

void add(int u, int v, int w)  //输入从u到v的长度为w的边
{
    edge[cnt].w = w;  //第cnt条边长为w
    edge[cnt].to = v;  //第cnt条边指向点v
    edge[cnt].next = head[u];  //上一条以u为起点的最大序号的边的序号是head[u]，每一条边都记录下了上一个同起点的边的序号，用next
    head[u] = cnt++;  //现在以u为起点的最大序号的边的序号是cnt了
}

/*int headre[maxn];

int cntre = 1;

void addreverse(int u, int v, int w)
{
    edgereverse[cntre].w = w;
    edgereverse[cntre].to = v;
    edgereverse[cntre].next = headre[u];
    headre[u] = cntre++;
}
*/
//---------- 建立边 ------------
ll Size[maxn];//表示的是以此为根节点的子树大小
ll ans=0;
int n,a,b,c;
void dfs(int u,int fa)
{
    Size[u]=1;
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==fa) continue;
        dfs(v,u);
        Size[u]+=Size[v];
        ans+=edge[i].w*abs(2*Size[v]-n);//这里把边权给了子节点！！！
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    //freopen("D:\\算法进阶\\树\\in.txt","r",stdin);
    cin>>n;
    for(int i=1;i<=n-1;i++)
    {
        cin>>a>>b>>c;
        add(a,b,c);
        add(b,a,c);
    }

    ans=0;
    dfs(1,0);
    cout<<ans<<endl;

    return 0;
}
