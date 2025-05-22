#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=200005;
int num=0;
struct Edge
{
    int u,v;
    double wei;
}edge[maxn<<1];

bool cmp(Edge  x,Edge y)
{
    return x.wei<y.wei;
}

int fa[maxn],n,m,cnt,x[maxn],y[maxn];
double ans=0;

double distance(int u,int v)
{
    return sqrt((x[u]-x[v])*(x[u]-x[v])+(y[u]-y[v])*(y[u]-y[v]));
}

int finded(int x)
{
    if(fa[x]==x) return x;
    return fa[x]=finded(fa[x]);
}//查找联通的边


void kruskal()
{
    sort(edge+1,edge+num+1,cmp);
    for(int i=1;i<=num;++i)
    {
        int eu=finded(edge[i].u),ev=finded(edge[i].v);
        if(eu==ev) continue;//已经联通了就跳过
        ans=edge[i].wei;
        fa[eu]=ev;//合并
        if(++cnt>=m-n)//限定在这里，用于限制鉴定的边数
        {
            printf("%.2lf",ans);
            return;

        }
    }
}

signed main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;++i)
        fa[i]=i;
    for(int i=1;i<=m;i++)
    {
        cin>>x[i]>>y[i];
    }

    for(int i=1;i<=m;++i)
    {
        for(int j=i+1;j<=m;j++)
        {
            edge[++num].u=i;
            edge[num].v=j;
            edge[num].wei=distance(i,j);
        }
    }
    kruskal();
    return 0;
}
