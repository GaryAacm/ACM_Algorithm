/*�߶������÷���ά��ǰ׺�ͺ�׺��ģ��*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;

int n,m;
int a[maxn];//��ʾ��ʼȫ��Ϊ0
struct node
{
    int sum,lsum,rsum;

}t[maxn<<2];

void push_up(int p,int l,int r)
{
    //�ȿ��ǲ��ܺϲ�
    t[p].lsum=t[p<<1].lsum,t[p].rsum=t[p<<1|1].rsum;
    t[p].sum=max(t[p<<1].sum,t[p<<1|1].sum);
    //ά�������Ҷ˵�
    int mid=l+r>>1;
    if(a[mid]!=a[mid+1])//���Ǻϲ������Ӵ���ͬ��Ҫ���£������俿�ҵ���һ���ּ��������俿�����һ�������γɵ��µķ���������������ܱ����������еĴ�
    {
        //Ϊ��ά�����Ӵ����ֵ������
        t[p].sum=max(t[p].sum,t[p<<1].rsum+t[p<<1|1].lsum);//�жϱ���ĺͺϲ�֮���

        if(t[p].lsum==mid-l+1) t[p].lsum+=t[p<<1|1].lsum; //�ж� x ����ǰ׺�Ƿ�Ҫ���£�����������ܸ�����ȫ���������������Լ����Ҷ˵��
        if(t[p].rsum==r-mid) t[p].rsum+=t[p<<1].rsum; //�ж� x ���Һ�׺�Ƿ�Ҫ����
    }
}

void build(int l,int r,int p)
{
    t[p].sum=t[p].lsum=t[p].rsum=1;//�������1
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
    if(L==R && pos==R) a[pos]^=1;//��ʾ���λ�ø�����
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

