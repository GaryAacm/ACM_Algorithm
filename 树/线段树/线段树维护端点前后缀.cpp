/*线段树利用分治维护前缀和后缀的模板*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;

int n,m;
int a[maxn];//表示初始全部为0
struct node
{
    int sum,lsum,rsum;

}t[maxn<<2];

void push_up(int p,int l,int r)
{
    //先考虑不能合并
    t[p].lsum=t[p<<1].lsum,t[p].rsum=t[p<<1|1].rsum;
    t[p].sum=max(t[p<<1].sum,t[p<<1|1].sum);
    //维护了左右端点
    int mid=l+r>>1;
    if(a[mid]!=a[mid+1])//考虑合并，连接处不同，要更新，左区间靠右的那一部分加上右区间靠左的那一部分所形成的新的符合条件的区间可能比左右区间中的大
    {
        //为了维护连接处出现的新情况
        t[p].sum=max(t[p].sum,t[p<<1].rsum+t[p<<1|1].lsum);//判断本身的和合并之后的

        if(t[p].lsum==mid-l+1) t[p].lsum+=t[p<<1|1].lsum; //判断 x 的左前缀是否要更新，就是左区间很给力，全部连接上来，所以加上右端点的
        if(t[p].rsum==r-mid) t[p].rsum+=t[p<<1].rsum; //判断 x 的右后缀是否要更新
    }
}

void build(int l,int r,int p)
{
    t[p].sum=t[p].lsum=t[p].rsum=1;//本身就有1
    if(l==r) return ;
    else
    {
        int mid=l+r>>1;
        build(l,mid,p<<1);
        build(mid+1,r,p<<1|1);
        push_up(p,l,r);
    }
}

void update(int pos,int p,int L,int R)
{
    if(L==R && pos==R) a[pos]^=1;//表示点的位置更新了
    else
    {
        int mid=L+R>>1;
        if(mid>=pos) update(pos,p<<1,L,mid);
        if(pos>=mid+1) update(pos,p<<1|1,mid+1,R);
        push_up(p,L,R);
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    build(1,n,1);
    while(m--)
    {
        int x;
        scanf("%d",&x);
        update(x,1,1,n);
        printf("%d\n",t[1].sum);
    }
    return 0;
}

