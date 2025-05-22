/*注意就是用克鲁斯卡尔来跑，然后就是默认不参加优惠的从0建立边*/
#include<bits/stdc++.h>
using namespace std;
struct node
{
        int u,v,w;
}e[250000];
int a,b,cnt,tot=1,ans,f[555];
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
        while(j<=cnt&&tot<=b)
    {
            if(finded(e[j].u)!=finded(e[j].v))
            {
                    tot++;
                    ans+=e[j].w;
                    join(e[j].u,e[j].v);
            }
            j++;
        }
}
int main()
{
        scanf("%d%d",&a,&b);
        for(int i=1;i<=b;i++)
        {
            for(int j=1;j<=b;j++)
            {
                int x;
                scanf("%d",&x);
                if(i<j&&x!=0) addedge(i,j,x);
            }
        }
        for(int i=1;i<=b;i++) addedge(0,i,a);
        for(int i=0;i<=b;i++) f[i]=i;
        sort(e+1,e+cnt+1,cmp);
        kruskal();
        printf("%d\n",ans);
        return 0;
}
