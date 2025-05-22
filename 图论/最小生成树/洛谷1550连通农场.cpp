#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;

struct node
{
    int u,v,w;
}e[maxn<<1];

int a,b,cnt,ans=0,f[maxn],n,m,s,t,u,v,w,x,tot=1;

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
    while(j<=cnt&&tot<=n)
    {
            if(finded(e[j].u)!=finded(e[j].v))
            {
                tot++;
                ans+=e[j].w;
                join(e[j].u,e[j].v);
            }
            j++;
    }
    cout<<ans<<endl;
}

int main()
{
        cin>>n;
        for(int i=1;i<=n;++i)
        {
            cin>>x;
            addedge(0,i,x);
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                cin>>x;
                if(i<j&&x!=0) addedge(i,j,x);
            }
        }
        for(int i=0;i<=n;i++) f[i]=i;
        sort(e+1,e+cnt+1,cmp);
        kruskal();
        return 0;
}


