#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e5+10;
typedef long long ll;

ll n,m,q,opt;
inline ll read()
{
	ll x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
ll a[maxn+2];
struct tree
{
    ll l,r;
    ll pre,add,mul;
}t[maxn*4+2];


void build(ll p,ll l,ll r)
{
    t[p].l=l;t[p].r=r;
    t[p].mul=1;//��ʼ��
    if(l==r)
    {
        t[p].pre=a[l]%m;
        return ;
    }
    ll mid=l+r>>1;//�����Ǿ��ѿ�
    build(p*2,l,mid);
    build(p*2+1,mid+1,r);
    t[p].pre=(t[p*2].pre+t[p*2+1].pre)%m;
}


void calc(tree &t,ll x,ll y)//������Ϣ�ļ���
{
    t.pre=(t.pre*x+(t.r-t.l+1)*y)%m;
    t.mul=t.mul*x%m;//�˷����ֱ�ӳ�
    t.add=(t.add*x+y)%m;//�ӷ����Ҫ���ϳ�������Ϊ��ʱ�����Ѿ�����
}


void spread(ll p)
{
    calc(t[p*2],t[p].mul,t[p].add);
    calc(t[p*2+1],t[p].mul,t[p].add);
    t[p].add=0;
    t[p].mul=1;//��������
}


void update1(ll p,ll x,ll y,ll k)//������޸�
{
     if(x<=t[p].l&&t[p].r<=y)//���串��
     {
         t[p].add=(t[p].add+k)%m;
         t[p].pre=((t[p].r-t[p].l+1)*k+t[p].pre)%m;//����ȡ�����Ĳ���
         return ;
     }
    spread(p);
    ll mid=t[p].l+t[p].r>>1;
    if(x<=mid) update1(p*2,x,y,k);
    if(y>mid) update1(p*2+1,x,y,k);
    t[p].pre=(t[p*2].pre+t[p*2+1].pre)%m;
}

void update2(ll p,ll x,ll y,ll k)
{
     if(x<=t[p].l&&t[p].r<=y)//���串��
     {
         t[p].add=(t[p].add*k)%m;
         t[p].mul=(t[p].mul*k)%m;
         t[p].pre=(t[p].pre*k)%m;
         return ;
     }
    spread(p);
    ll mid=t[p].l+t[p].r>>1;
    if(x<=mid) update2(p*2,x,y,k);
    if(y>mid) update2(p*2+1,x,y,k);
    t[p].pre=(t[p*2].pre+t[p*2+1].pre)%m;
}


long long query(ll p,ll x,ll y)
{
    if(x<=t[p].l&&t[p].r<=y)//���串��
    {
        return t[p].pre;
    }
    spread(p);//�����Ǿ����´���
    ll mid=t[p].l+t[p].r>>1;//�����Ǿ��ѿ�
    long long ans=0;
    if(x<=mid) ans=(ans+query(p*2,x,y))%m;
    if(y>mid) ans=(ans+query(p*2+1,x,y))%m;//�������������Ĺ���
    return ans;
}

signed main()
{
    n=read(),q=read(),m=read();
    for(int i=1;i<=n;++i)
    {
        a[i]=read();
    }
    build(1,1,n);
    while(q--)
    {
        opt=read();
        if(opt==1)//���
        {
            ll x=read(),y=read(),k=read();
            update2(1,x,y,k);
        }
        else if(opt==2)//���
        {
            ll x=read(),y=read(),k=read();
            update1(1,x,y,k);
        }
        else
        {
            ll x=read(),y=read();
            printf("%d\n",query(1,x,y));
        }

    }
    return 0;
}
