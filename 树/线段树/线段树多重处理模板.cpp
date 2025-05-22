#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
typedef long long ll;

//-----------------------------------ǰ��Ĵ���-------------------------------------
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

//һ������ӵ�����ǣ�����һ�����жϷ񸲸ǵı��,�������Ǹ��ǵ�ֵ

inline int ls(int p)
{
    return p<<1;//�����
}
inline int rs(int p)
{
    return p<<1|1;//�Ҷ���
}

//-------------------------------����-----------------------------------

void build(int p,int l,int r)//����
{
    t[p].l=l;
    t[p].r=r;
    if(l==r)//�Ѿ���Ҷ�ӽڵ�
    {
        t[p].pre=a[l];
        return ;
    }
    int mid=(l+r)>>1;
    build(ls(p),l,mid);
    build(rs(p),mid+1,r);
    //������¼�����ֵ���
    t[p].pre=max(t[ls(p)].pre,t[rs(p)].pre);//�������ֽڵ������ֵ
}

//-------------------------------�����޸�-----------------------------------

//-------------------------------���Ǳ�Ǵ���-----------------------------------
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

//-------------------------------��ӱ�Ǵ���-----------------------------------
void sumdown(int p)
{
    if(t[p].add)
    {
        coverdown(p);
        //����Ƿ��㣬���´��ݸ��ֽڵ�
        t[ls(p)].pre+=t[p].add;//����������ı仯���������䳤��
        t[rs(p)].pre+=t[p].add;
        t[ls(p)].add+=t[p].add;
        t[rs(p)].add+=t[p].add;//��������Ǹ������ӽڵ�
        t[p].add=0;
    }
}


inline void spread(int p)
{
    coverdown(p);
    sumdown(p);
}

//---------------------------��������----------------------------------

void update(int p,int x,int y,int k,int op)//x��y�����䷶Χ��k���޸ĵ�ֵ��p�ǽڵ�
{
    if(op==2)
    {
        if(x<=t[p].l&&t[p].r<=y)//�������
        {
            t[p].pre+=k;
            t[p].add+=k;

            return;
        }
    }
    else//���ǲ���
    {
        if(x<=t[p].l&&t[p].r<=y)//���串��
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


//-----------------------------�����ѯ��ֵ-----------------------------------------

long long query(int p,int x,int y)
{
    if(x<=t[p].l&&t[p].r<=y)//���串��
    {
        return t[p].pre;
    }
    spread(p);//�����Ǿ����´���
    int mid=t[p].l+t[p].r>>1;//�����Ǿ��ѿ�
    long long ans=-1e18;
    if(x<=mid) ans=max(ans,query(ls(p),x,y));
    if(y>mid) ans=max(ans,query(rs(p),x,y));//�������������Ĺ���
    return ans;
}

//------------------------------���Ĵ���---------------------------------

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

        if(op==1)//���串��
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


