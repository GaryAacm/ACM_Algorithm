#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
ll n,k,a[maxn],cnt,b[maxn];

void Merge(ll l,ll mid,ll r)
{
    ll i=l,j=mid+1,t=0;//i，j分别表示两个区间的开头
    while(i<=mid&&j<=r)
    {
        if(a[i]>a[j])//大的数在前面
        {
            b[t++]=a[j++];//小的数加入b里面
            cnt+=mid-i+1;//逆序数就是当前的两个区间当前位置的差值，因为区间内部已经有序
        }
        else
            b[t++]=a[i++];//否则就是小的数进去，不会有逆序数

    }
    while(i<=mid) b[t++]=a[i++];//未处理完的区间复制过去，就是两个区间长短不一样
    while(j<=r) b[t++]=a[j++];//未处理完的放在最后面
    for(i=0;i<t;i++) a[l+i]=b[i];//排好序的放回去
}

void Mergesort(ll l,ll r)
{
    if(l<r)//分割区间
    {
        ll mid=l+r>>1;
        Mergesort(l,mid);
        Mergesort(mid+1,r);
        Merge(l,mid,r);//合并区间
    }
}

int main()
{
    while(scanf("%lld%lld",&n,&k)!=EOF)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);//输入数据
        }
        cnt=0;
        Mergesort(0,n-1);//归并排序
        if(cnt<=k) printf("0\n");
        else
            printf("%lld\n",cnt-k);
    }
    return 0;
}
