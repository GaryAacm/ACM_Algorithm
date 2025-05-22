/*利用最小生成树合并多余的*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=2e4+10;

struct node
{
    int u,v,w;
}e[maxn<<1];

int a,b,cnt,ans=0,f[maxn],n,m,s,t,u,v,w,countt=0;

bool cmp(node x,node y)
{
    return x.w<y.w;
}

int finded(int x)
{
    if(f[x]==x) return x;
    return f[x]=finded(f[x]);
}

void join(int x,int y)
{
        int xx=finded(x);
        int yy=finded(y);
        if(xx!=yy) f[xx]=yy;
}

void addedge(int x,int y,int z)
{
        cnt++;
        e[cnt].u=x;
        e[cnt].v=y;
        e[cnt].w=z;
}

void kruskal()
{
    int j=1;
    while(j<=m)
    {
        if(finded(e[j].u)!=finded(e[j].v))
        {
            ans+=e[j].w;
            join(e[j].u,e[j].v);
            countt++;//用到的边数
        }
        j++;
        if(n-s<=countt)
            break;
    }
    if(n-s<=countt)//把剩下的要连在一起，就是要减少n-s个，那就要合并n-s+1个
        cout<<ans<<endl;
    else
        cout<<"No Answer"<<endl;
}

int main()
{
        scanf("%d%d%d",&n,&m,&s);
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            addedge(u,v,w);
        }
        for(int i=0;i<=n;i++) f[i]=i;
        sort(e+1,e+m+1,cmp);
        kruskal();
        return 0;
}

