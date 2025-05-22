#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
struct Node
{
    int l,r,sum;
}tree[MAXN*4];

int N,T,Q,L,R,opt,lazy[MAXN*4];
char c[5];

//------------------------建树----------------------------//

void build_tree(int k,int l,int r)
{
    tree[k].l=l,tree[k].r=r;
    if(l==r){tree[k].sum=1;return ;}
    int mid=l+r>>1;
    build_tree(k<<1,l,mid);build_tree(k<<1|1,mid+1,r);
    tree[k].sum=tree[k<<1].sum|tree[k<<1|1].sum;
}


//----------------------传递懒标记----------------------------------//

void pushdown(int k)
{
    if(!lazy[k])return ;
    tree[k<<1].sum=lazy[k],lazy[k<<1]=lazy[k];
    tree[k<<1|1].sum=lazy[k],lazy[k<<1|1]=lazy[k];
    lazy[k]=0;
}

//----------------------------更新--------------------------//

void update(int k,int l,int r,int x)
{
    if(tree[k].l>=l&&tree[k].r<=r){tree[k].sum=x,lazy[k]=x;return;}//区间覆盖修改值
    if(tree[k].l>r||tree[k].r<l) return ;
    pushdown(k);
    update(k<<1,l,r,x);
    update(k<<1|1,l,r,x);
    tree[k].sum=tree[k<<1].sum|tree[k<<1|1].sum;//保留存在的二进制
}

//----------------------查询--------------------------//

int query(int k,int l,int r)
{
    if(tree[k].l>=l&&tree[k].r<=r)return tree[k].sum;
    if(tree[k].l>r||tree[k].r<l)return 0;
    pushdown(k);
    return query(k<<1,l,r)|query(k<<1|1,l,r);
}

//---------------------------------------------------------//
int main()
{
    scanf("%d%d%d",&N,&T,&Q);
    build_tree(1,1,N);
    while(Q--)
    {
        scanf("%s%d%d",c,&L,&R);
        if(L>R)swap(L,R);

        if(c[0]=='C')
        {
            scanf("%d",&opt);
            opt=(1<<opt-1);//状态压缩颜色
            //cout<<"opt: "<<opt<<endl;
            update(1,L,R,opt);
        }
        else
        {
            int res=query(1,L,R),ans=0;
            while(res)
            {
                if(res&1)ans++;//判断有几位不同的二进制，复位二进制
                res>>=1;
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
