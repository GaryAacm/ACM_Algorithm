#include<bits/stdc++.h>
using namespace std;

const int maxn=1e5+5;//与poj那个不同，那个是以1为根节点，这里要所有的点遍历
int ans;
struct Edge{int from,to;}edge[maxn];//答案的边，最后需要排序

bool cmp(const Edge a,const Edge b){if(a.from!=b.from)return a.from<b.from;return a.to<b.to;}//答案边的比较函数

inline void add_edge(int x,int y){edge[ans].from=min(x,y);edge[ans].to=max(x,y);ans++;}//在答案中加入一条边

vector<int> v[maxn];
int low[maxn],num[maxn];

int cnt=0;
void dfs(int u,int fa)
{
    low[u]=num[u]=++cnt;//更新初始值
    //int child=0;
    bool vis=false;
    for(int i=0;i<v[u].size();i++)
    {
        int kid=v[u][i];
        if(!num[kid])//子节点没有访问过,可以继续更新
        {

            dfs(kid,u);//递归最后一层

            if(low[kid]>num[u])//根节点单独处理（书上定理讲了，上面是非根节点的才处理）
            {
                //cout<<"out"<<endl;
                add_edge(u,kid);
            }
            low[u]=min(low[u],low[kid]);//更新子节点能够回退的点
        }

        else
		{
			if(kid==fa&&!vis)vis=true;//判断重复边
            else  low[u]=min(low[u],num[kid]);
		}

		/*if(num[kid]&&kid!=fa)//割边要多一些判断条件
		{
			//if(kid==fa&&!vis)vis=true;//判断重复边
             low[u]=min(low[u],num[kid]);
		}*/
    }

}
int n,m;
int main()
{

    //freopen("D:\\算法进阶\\图论\\无向图的连通性\\in.txt","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=1;i<=n;i++)
    {
        if(!num[i])
           dfs(i,i);
    }

    sort(edge,edge+ans,cmp);//将答案序列排个序
    //cout<<ans<<endl;
    for(int i=0;i<ans;i++)
    {
        printf("%d %d\n",edge[i].from,edge[i].to);

    }

    return 0;
}
