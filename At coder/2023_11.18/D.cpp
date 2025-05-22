#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
int n, m;
int cnt[N];
int win = 0;

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; ++i) {
        int x;
        scanf("%d", &x);
        ++cnt[x];
        if(cnt[x] > cnt[win] || (cnt[x] == cnt[win] && x < win)) {
            win = x;
        }
        printf("%d\n", win);
    }
    return 0;
}






/*#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
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
        t[p].pre=a[l];
        return ;
    }
    int mid=(l+r)>>1;
    build(ls(p),l,mid);
    build(rs(p),mid+1,r);
    t[p].pre=t[ls(p)].pre+t[rs(p)].pre;//�������ֽڵ���¸��ڵ�
}
//�����޸�
//��������´��ݣ���������ֵ
void spread(int p)
{
    if(t[p].add)
    {
        //����Ƿ��㣬���´��ݸ��ֽڵ�
        t[ls(p)].pre+=t[p].add*(t[ls(p)].r-t[ls(p)].l+1);//�������䳤��
        t[rs(p)].pre+=t[p].add*(t[rs(p)].r-t[rs(p)].l+1);
        t[ls(p)].add+=t[p].add;
        t[rs(p)].add+=t[p].add;//��������Ǹ������ӽڵ�
        t[p].add=0;//���ڵ�����
    }
}
void update(int p,int x,int y,int k)//x��y�����䷶Χ��k���޸ĵ�ֵ��p�ǽڵ�
{
    if(x<=t[p].l&&t[p].r<=y)//���串��
    {
        t[p].pre+=(t[p].r-t[p].l+1)*k;
        t[p].add+=k;
        return;//�������ǣ�ֱ�ӷ���
    }
    //û�и������ѿ����䲢�����ӽڵ�,���ӽڵ�ȥ�ҷ���Ҫ�������
    spread(p);
    int mid=t[p].l+t[p].r>>1;
    if(x<=mid) update(ls(p),x,y,k);
    if(y>mid) update(rs(p),x,y,k);
    t[p].pre=t[ls(p)].pre+t[rs(p)].pre;
}
//�����ѯ
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
int main()
{
    freopen("D:\\�㷨����\\At coder\\2023_11.18\\in.txt","r",stdin);
    int n,m;
    n=read(),m=read();
    for(int i=1;i<=n;++i)
    {
        a[i]=0;
    }
    build(1,1,n);
    for(int i=1;i<=m;++i)
    {
        int q;
        q=read();//�����ֶ�
        update(1,q,q,1);
        printf("%d\n",query(1,1,n));

    }
    return 0;
}*/

