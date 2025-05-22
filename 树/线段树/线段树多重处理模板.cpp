#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
typedef long long ll;

//-----------------------------------前面的处理-------------------------------------
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int n,l,r,m;
int a[maxn+2];

struct tree
{
    int l,r;
    ll pre,add,cover,val;
}t[maxn*4+2];

//一个是相加的懒标记，另外一个是判断否覆盖的标记,第三个是覆盖的值

inline int ls(int p)
{
    return p<<1;//左儿子
}
inline int rs(int p)
{
    return p<<1|1;//右儿子
}

//-------------------------------建树-----------------------------------

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
    //后面更新加是最值相加
    t[p].pre=max(t[ls(p)].pre,t[rs(p)].pre);//用左右字节点更新最值
}

//-------------------------------区间修改-----------------------------------

//-------------------------------覆盖标记传递-----------------------------------
void coverdown(int p)
{
    if(t[p].cover)
    {
        t[ls(p)].val=t[p].val;
        t[rs(p)].val=t[p].val;
        t[ls(p)].cover=t[rs(p)].cover=1;
        t[ls(p)].pre=t[ls(p)].val;
        t[rs(p)].pre=t[rs(p)].val;
        t[ls(p)].add=t[rs(p)].add=0;
        t[p].cover=0;
    }
}

//-------------------------------相加标记传递-----------------------------------
void sumdown(int p)
{
    if(t[p].add)
    {
        coverdown(p);
        //懒标记非零，向下传递给字节点
        t[ls(p)].pre+=t[p].add;//区间这个数的变化，不乘区间长度
        t[rs(p)].pre+=t[p].add;
        t[ls(p)].add+=t[p].add;
        t[rs(p)].add+=t[p].add;//传递懒标记给左右子节点
        t[p].add=0;
    }
}


inline void spread(int p)
{
    coverdown(p);
    sumdown(p);
}

//---------------------------更新区间----------------------------------

void update(int p,int x,int y,int k,int op)//x，y是区间范围，k是修改的值，p是节点
{
    if(op==2)
    {
        if(x<=t[p].l&&t[p].r<=y)//区间加数
        {
            t[p].pre+=k;
            t[p].add+=k;

            return;
        }
    }
    else//覆盖操作
    {
        if(x<=t[p].l&&t[p].r<=y)//区间覆盖
        {
            t[p].val=k;
            t[p].add=0;
            t[p].pre=k;
            t[p].cover=1;
            //cout<<"in"<<endl;
            return ;
        }
    }
    spread(p);

    int mid=t[p].l+t[p].r>>1;
    if(x<=mid) update(ls(p),x,y,k,op);
    if(y>mid) update(rs(p),x,y,k,op);

    t[p].pre=max(t[ls(p)].pre,t[rs(p)].pre);
}


//-----------------------------区间查询最值-----------------------------------------

long long query(int p,int x,int y)
{
    if(x<=t[p].l&&t[p].r<=y)//区间覆盖
    {
        return t[p].pre;
    }
    spread(p);//不覆盖就向下传递
    int mid=t[p].l+t[p].r>>1;//不覆盖就裂开
    long long ans=-1e18;
    if(x<=mid) ans=max(ans,query(ls(p),x,y));
    if(y>mid) ans=max(ans,query(rs(p),x,y));//加上左右子树的贡献
    return ans;
}

//------------------------------核心处理---------------------------------

signed main()
{
    n=read(),m=read();
    for(int i=1;i<=n;++i)
    {
        a[i]=read();
    }
    build(1,1,n);
    //cout<<"in"<<endl;
    for(int i=1;i<=m;++i)
    {
        int op,x,y,k;
        op=read();

        if(op==1)//区间覆盖
        {
            x=read(),y=read(),k=read();
            update(1,x,y,k,op);
        }

        else if(op==2)
        {
            x=read(),y=read(),k=read();
            update(1,x,y,k,op);
        }
        else
        {
            x=read(),y=read();
            printf("%lld\n",query(1,x,y));
        }
    }
    return 0;
}


