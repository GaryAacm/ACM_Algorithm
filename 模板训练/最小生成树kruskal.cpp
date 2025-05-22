#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=200005;
struct Edge
{
    int u,v,wei;
}edge[maxn<<1];

bool cmp(Edge  x,Edge y)
{
    return x.wei<y.wei;
}

int fa[maxn],ans,n,m,cnt;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}

int finded(int x)
{
    if(fa[x]==x) return x;
    return fa[x]=finded(fa[x]);
}//查找联通的边

void kruskal()
{
    sort(edge,edge+m,cmp);
    for(int i=0;i<m;++i)
    {
        int eu=finded(edge[i].u),ev=finded(edge[i].v);
        if(eu==ev) continue;//已经联通了就跳过
        ans+=edge[i].wei;
        fa[eu]=ev;//合并
        if(++cnt==n-1)
        {
            cout<<ans<<endl;
            return;
        }
    }
    cout<<"orz"<<endl;
}

signed main()
{
    n=read(),m=read();
    for(int i=1;i<=n;++i)
        fa[i]=i;
    for(int i=0;i<m;++i)
    {
        edge[i].u=read(),edge[i].v=read(),edge[i].wei=read();
    }
    kruskal();
    return 0;
}
