#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2005;
struct Edge
{
    ll u,v,wei;
}edge[maxn];

bool cmp(Edge x,Edge y)
{
    return x.wei<y.wei;
}

ll fa[maxn],ans,n,m,cnt,k;
inline ll read()
{
	ll x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}

ll find(ll x)
{
    if(fa[x]==x) return x;
    return fa[x]=find(fa[x]);
}//������ͨ�ı�

void kruskal()
{
    sort(edge,edge+m,cmp);
    for(int i=0;i<m;++i)
    {
        ll eu=(find(edge[i].u)),ev=(find(edge[i].v));
        if(eu==ev) continue;//�Ѿ���ͨ�˾�����
        ans=(ans+edge[i].wei)%k;
        fa[eu]=ev;//�ϲ�
        if(++cnt==n-1)
        {
            cout<<(ll)(ans%k)<<endl;
            return;
        }
    }
    //cout<<"orz"<<endl;
}

int main()
{
    freopen("D:\\�㷨����\\At coder\\in.txt","r",stdin);
    n=read(),m=read(),k=read();
    for(int i=1;i<=n;++i)
        fa[i]=i;
    for(int i=0;i<m;++i)
    {
        edge[i].u=read(),edge[i].v=read(),edge[i].wei=read();
    }
    kruskal();
    return 0;
}
