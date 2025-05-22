#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e5+10;
typedef long long ll;

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int n,l,r;
int a[maxn+2];
struct tree
{
    int l,r;
    ll pre,add,minn,maxx;//懒标记表示要减去的数值
}t[maxn*4+2];
inline int ls(int p)
{
    return p<<1;//左儿子
}
inline int rs(int p)
{
    return p<<1|1;//右儿子
}

//=================建树===================//
void build(int p,int l,int r)//建树
{
    t[p].l=l;
    t[p].r=r;
    if(l==r)
    {
        t[p].pre=t[p].minn =t[p].maxx=a[l];
        return ;
    }
    int mid=(l+r)>>1;
    build(ls(p),l,mid);
    build(rs(p),mid+1,r);
    t[p].pre=t[ls(p)].pre+t[rs(p)].pre;
    t[p].minn=min(t[p*2].minn,t[p*2+1].minn);
    t[p].maxx=max(t[p*2].maxx,t[p*2+1].maxx);
    return ;
}


//区间修改
void spread(int p)
{
    if(t[p].add)
    {
        int k=t[p].add;
        t[ls(p)].pre-=t[p].add*(t[ls(p)].r-t[ls(p)].l+1);//改变区间的值
        t[rs(p)].pre-=t[p].add*(t[rs(p)].r-t[rs(p)].l+1);
        t[ls(p)].add+=t[p].add;
        t[rs(p)].add+=t[p].add;//传递懒标记给左右子节点
        t[p*2].minn-=k;
        t[p*2].maxx-=k;
        t[p*2+1].minn-=k;
        t[p*2+1].maxx-=k;
        t[p].add=0;//父节点清零
        return;
    }
}

void do_sqrt(int p,int x,int y)//x，y是区间范围，k是修改的值，p是节点
{
    if(x<=t[p].l&&t[p].r<=y&&(t[p].minn-(ll)sqrt(t[p].minn))==(t[p].maxx-(ll)sqrt(t[p].maxx)))//对相等不影响区间的整段处理
    {
        ll k=t[p].minn-(ll)sqrt(t[p].minn);
        t[p].pre-=(t[p].r-t[p].l+1)*k;//这样对整体区间不影响
        t[p].add+=k;
        t[p].minn-=k;
        t[p].maxx-=k;
        return;
    }

    spread(p);
    int mid=t[p].l+t[p].r>>1;
    if(x<=mid) do_sqrt(ls(p),x,y);
    if(y>mid) do_sqrt(rs(p),x,y);
    t[p].pre=t[ls(p)].pre+t[rs(p)].pre;
    t[p].minn=min(t[p*2].minn,t[p*2+1].minn);
    t[p].maxx=max(t[p*2].maxx,t[p*2+1].maxx);
    return ;
}
//===================区间查询==================//
long long query(int p,int x,int y)
{
    if(x<=t[p].l&&t[p].r<=y)//区间覆盖返回整个区间的值
    {
        return t[p].pre;
    }
    spread(p);
    int mid=t[p].l+t[p].r>>1;//不覆盖就裂开找子区间
    long long ans=0;
    if(x<=mid) ans+=query(ls(p),x,y);
    if(y>mid) ans+=query(rs(p),x,y);//加上左右子树的贡献
    return ans;
}

signed main()
{
    int n,m;
    n=read();
    for(int i=1;i<=n;++i)
    {
        a[i]=read();
    }
    m=read();
    build(1,1,n);
    for(int i=1;i<=m;++i)
    {
        int q,x,y,k;
        q=read();//操作手段
        if(q==0)
        {
            x=read(),y=read();
            if(x>y) swap(x,y);
            do_sqrt(1,x,y);
        }
        else
        {
            x=read(),y=read();
            if(x>y) swap(x,y);
            printf("%lld\n",query(1,x,y));
        }
    }
    return 0;
}
