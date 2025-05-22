#include<bits/stdc++.h>
using namespace std;
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

int change(int p)//�ı�����ǣ�1��ʾҪ�޸ģ�0��ʾ�Ѿ��Ĺ���
{
	if(p==1)
		return 0;
	return 1;
}
struct tree
{
    int l,r;
    ll pre,add;
}t[maxn*4+2];
inline int ls(int p)
{
    return p<<1;//�����
}
inline int rs(int p)
{
    return p<<1|1;//�Ҷ���
}

void build(int p,int l,int r)//����
{
    t[p].l=l;
    t[p].r=r;
    if(l==r)//�Ѿ���Ҷ�ӽڵ�
    {
        t[p].pre=0;
        return ;
    }
    int mid=(l+r)>>1;
    build(ls(p),l,mid);
    build(rs(p),mid+1,r);
    t[p].pre=t[ls(p)].pre+t[rs(p)].pre;//�������ֽڵ���¸��ڵ�
}


//-----------------------�����޸�---------------------------


//--------------------------��������´��ݣ���������ֵ-------------------------
void spread(int p)
{
    if(t[p].add)//����Ǳ�������Ƿ�����޸�
    {
        //����Ƿ��㣬���´��ݸ��ֽڵ�
        t[ls(p)].pre=(t[ls(p)].r-t[ls(p)].l+1)-t[ls(p)].pre;//�������䳤��
        t[rs(p)].pre=(t[rs(p)].r-t[rs(p)].l+1)-t[rs(p)].pre;
        t[ls(p)].add=change(t[ls(p)].add);
        t[rs(p)].add=change(t[rs(p)].add);//��������Ǹ������ӽڵ�
        t[p].add=0;//���ڵ�����
    }
}


//----------------------------��������--------------------------------

void update(int p,int x,int y)//x��y�����䷶Χ,p�ǽڵ�1��ʼ
{
    if(x<=t[p].l&&t[p].r<=y)//���串��
    {
        t[p].pre=(t[p].r-t[p].l+1)-t[p].pre;//�������еĺ͹��˵�
        t[p].add=change(t[p].add);
        return;
    }
    //û�и������ѿ����䲢�����ӽڵ�,���ӽڵ�ȥ�ҷ���Ҫ�������
    spread(p);
    int mid=t[p].l+t[p].r>>1;
    if(x<=mid) update(ls(p),x,y);
    if(y>mid) update(rs(p),x,y);
    t[p].pre=t[ls(p)].pre+t[rs(p)].pre;
}

//-----------------------------�����ѯ----------------------------------

long long query(int p,int x,int y)
{
    if(x<=t[p].l&&t[p].r<=y)//���串��
    {
        return t[p].pre;
    }
    spread(p);//�����Ǿ����´���
    int mid=t[p].l+t[p].r>>1;//�����Ǿ��ѿ�
    long long ans=0;
    if(x<=mid) ans+=query(ls(p),x,y);
    if(y>mid) ans+=query(rs(p),x,y);//�������������Ĺ���
    return ans;
}

//----------------------------------------------------------------
int main()
{
    int n,m;
    n=read(),m=read();
    build(1,1,n);
    for(int i=1;i<=m;++i)
    {
        int q,x,y,k;
        q=read();//�����ֶ�
        if(q==0)//���������
        {
            x=read(),y=read();
            update(1,x,y);
        }
        else
        {
            x=read(),y=read();
            printf("%lld\n",query(1,x,y));
        }
    }
    return 0;
}


