#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
typedef long long ll;
//线段树的原理就是不断对区间进行划分
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
    ll pre,add;
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
    if(l==r)//已经是叶子节点
    {
        t[p].pre=a[l];
        return ;
    }
    int mid=(l+r)>>1;
    build(ls(p),l,mid);
    build(rs(p),mid+1,r);
    t[p].pre=t[ls(p)].pre+t[rs(p)].pre;//用左右字节点更新父节点
}
//区间修改
//懒标记向下传递，更新区间值
void spread(int p)
{
    if(t[p].add)
    {
        //懒标记非零，向下传递给字节点
        t[ls(p)].pre+=t[p].add*(t[ls(p)].r-t[ls(p)].l+1);//改变区间的值
        t[rs(p)].pre+=t[p].add*(t[rs(p)].r-t[rs(p)].l+1);
        //cout<<"ls(p):"<<' '<<ls(p)<<"值："<<t[ls(p)].pre<<' '<<"rs(p): "<<rs(p)<<"值："<<t[rs(p)].pre<<endl;
        t[ls(p)].add+=t[p].add;
        t[rs(p)].add+=t[p].add;//传递懒标记给左右子节点
        t[p].add=0;//父节点清零
    }
}

void update(int p,int x,int y,int k)//x，y是区间范围，k是修改的值，p是节点
{
    if(x<=t[p].l&&t[p].r<=y)//区间覆盖才会有懒标记，标记当前的节点
    {
        t[p].pre+=(t[p].r-t[p].l+1)*k;//区间的整个值发生变化，用k为了不重复计算
        t[p].add+=k;//一直累加
        return;//标记懒标记，直接返回
    }
    //没有覆盖则裂开区间并传给子节点,由子节点去找符合要求的区间
    //cout<<"此时的p："<<p<<endl;
    spread(p);//为了处理已经标记了的区间，就是多重标记，多次区间操作

    //处理有交集的情况
    int mid=t[p].l+t[p].r>>1;
    if(x<=mid) update(ls(p),x,y,k);
    if(y>mid) update(rs(p),x,y,k);

    t[p].pre=t[ls(p)].pre+t[rs(p)].pre;
    return ;
}
//===================区间查询==================//
//只有在查询的时候才会记录已有的懒标记来更新
long long query(int p,int x,int y)
{
    if(x<=t[p].l&&t[p].r<=y)//区间覆盖返回整个区间的值
    {
        return t[p].pre;
    }
    //cout<<"此时的p："<<p<<endl;
    spread(p);//不覆盖就向下传递，此时会根据区间进行更新，没有更新到的在懒标记里面保留，为下次查询更新做准备
    int mid=t[p].l+t[p].r>>1;//不覆盖就裂开找子区间
    long long ans=0;
    if(x<=mid) ans+=query(ls(p),x,y);
    if(y>mid) ans+=query(rs(p),x,y);//加上左右子树的贡献
    return ans;
}

int main()
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
        q=read();//操作手段
        if(q==1)//区间加上数
        {
            x=read(),y=read(),k=read();
            update(1,x,y,k);
        }
        else
        {
            x=read(),y=read();
            printf("%lld\n",query(1,x,y));
        }
    }
    return 0;
}

