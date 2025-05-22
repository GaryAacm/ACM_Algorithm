//注意最小生成树是单向边，然后就是这里排好了顺序，只要联通就是最大值最小
#include<bits/stdc++.h>
using namespace std;
const int maxn=2e4+10;

struct node
{
    int u,v,w;
}e[maxn<<1];

int a,b,cnt,ans,f[maxn],n,m,s,t,u,v,w;

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
            join(e[j].u,e[j].v);
        }

        if(finded(s)==finded(t))
        {
            cout<<e[j].w<<endl;
            return;
        }
        j++;
    }
}

int main()
{
        //freopen("C:\\Users\\asus\\Desktop\\in.txt","r",stdin);
        scanf("%d%d%d%d",&n,&m,&s,&t);
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            addedge(u,v,w);
            //addedge(v,u,w);
            /*
            e[i].u=u;
            e[i].v=v;
            e[i].w=w;*/
        }
        for(int i=0;i<=n;i++) f[i]=i;
        sort(e+1,e+m+1,cmp);
        kruskal();
        return 0;
}
