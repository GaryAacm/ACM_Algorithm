#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e6+10;
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
struct Tree
{
    int l,r;
    ll pre,maxleft,maxright,ans;
}t[maxn];
inline int ls(int p)
{
    return p<<1;//左儿子
}
inline int rs(int p)
{
    return p<<1|1;//右儿子
}

//===============合并区间最值============//
void putin(int p)
{
    t[p].pre=t[2*p].pre+t[2*p+1].pre;
    t[p].maxleft=max(t[2*p].maxleft,t[2*p].pre+t[2*p+1].maxleft);
    t[p].maxright=max(t[2*p+1].maxright,t[2*p].maxright+t[2*p+1].pre);
    t[p].ans=max(max(t[p*2].ans,t[p*2+1].ans),t[p*2].maxright+t[p*2+1].maxleft);
}



//=================建树===================//
void build(int p,int l,int r)//建树
{
    t[p].l=l;
    t[p].r=r;
    if(l==r)//已经是叶子节点
    {
        t[p].pre=a[l];
        t[p].ans=t[p].maxleft=t[p].maxright=a[l];
        return ;
    }
    int mid=(l+r)>>1;
    build(ls(p),l,mid);
    build(rs(p),mid+1,r);
    putin(p);
}

//=============单点修改=====================//

void update(int p,int x,int k)
{
    if(t[p].l==t[p].r)
    {
        t[p].pre=t[p].maxleft=t[p].maxright=t[p].ans=k;
        return;
    }
    int mid=t[p].l+t[p].r>>1;
    if(x<=mid) update(ls(p),x,k);
    else update(rs(p),x,k);
    putin(p);
}
//===================区间查询==================//
Tree query(int p,int x,int y)
{
    if(x<=t[p].l&&t[p].r<=y)
    {
        return t[p];
    }

    int mid=t[p].l+t[p].r>>1;

    if(y<=mid) return query(ls(p),x,y);
    else
    {
        if(x>mid) return query(rs(p),x,y);
        else
        {
            Tree t,a=query(ls(p),x,y),b=query(rs(p),x,y);
            t.maxleft=max(a.maxleft,a.pre+b.maxleft);
            t.maxright=max(b.maxright,a.maxright+b.pre);
            t.ans=max(max(a.ans,b.ans),a.maxright+b.maxleft);
            return t;
        }
    }
}

signed main()
{
    int n,m;
    n=read(),m=read();
    for(int i=1;i<=n;++i)
    {
        a[i]=read();
    }
    build(1,1,n);

    for(int i=1;i<=m;++i)
    {
        int q,x,y,k;
        q=read();
        if(q==2)
        {
            x=read(),y=read();
            update(1,x,y);
        }
        else
        {
            x=read(),y=read();
            if(x>y) swap(x,y);
            printf("%lld\n",query(1,x,y).ans);
        }
    }
    return 0;
}

