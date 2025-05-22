#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
struct Edge
{
    int u,v,wei;
}edge[maxn*maxn];

bool cmp(Edge x,Edge y)
{
    return x.wei<y.wei;
}

int fa[maxn],ans,n,m,cnt;

/*inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}*/

int finded(int x)
{
    if(fa[x]==x) return x;
    return fa[x]=finded(fa[x]);
}//查找联通的边

/*void join(int x,int y)
{
    int c1=finded(x),c2=finded(y);
    if(c1!=c2) fa[c1]=c2;
}*/

int kruskal()
{
    ans=0;
    for(int i=1;i<=n;i++) fa[i]=i;
    sort(edge+1,edge+1+m,cmp);
    for(int i=1;i<=m;++i)//遍历所有的边查找
    {
        int c1=finded(edge[i].u),c2=finded(edge[i].v);
        if(c1==c2) continue;//产生了圈
        fa[c1]=c2;
        ans+=edge[i].wei;
    }
    return ans;
}

int main()
{
    //freopen("D:\\算法进阶\\图论\\最小生成树\\in.txt","r",stdin);
    while(scanf("%d",&n)!=EOF&&n)
    {
        m=n*(n-1)/2;
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].wei);
        }

        printf("%d\n",kruskal());
    }

    return 0;
}
