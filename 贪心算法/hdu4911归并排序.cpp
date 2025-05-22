#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
ll n,k,a[maxn],cnt,b[maxn];

void Merge(ll l,ll mid,ll r)
{
    ll i=l,j=mid+1,t=0;//i��j�ֱ��ʾ��������Ŀ�ͷ
    while(i<=mid&&j<=r)
    {
        if(a[i]>a[j])//�������ǰ��
        {
            b[t++]=a[j++];//С��������b����
            cnt+=mid-i+1;//���������ǵ�ǰ���������䵱ǰλ�õĲ�ֵ����Ϊ�����ڲ��Ѿ�����
        }
        else
            b[t++]=a[i++];//�������С������ȥ��������������

    }
    while(i<=mid) b[t++]=a[i++];//δ����������临�ƹ�ȥ�������������䳤�̲�һ��
    while(j<=r) b[t++]=a[j++];//δ������ķ��������
    for(i=0;i<t;i++) a[l+i]=b[i];//�ź���ķŻ�ȥ
}

void Mergesort(ll l,ll r)
{
    if(l<r)//�ָ�����
    {
        ll mid=l+r>>1;
        Mergesort(l,mid);
        Mergesort(mid+1,r);
        Merge(l,mid,r);//�ϲ�����
    }
}

int main()
{
    while(scanf("%lld%lld",&n,&k)!=EOF)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);//��������
        }
        cnt=0;
        Mergesort(0,n-1);//�鲢����
        if(cnt<=k) printf("0\n");
        else
            printf("%lld\n",cnt-k);
    }
    return 0;
}
