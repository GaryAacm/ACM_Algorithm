#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
ll b[maxn],c[maxn],a[maxn];
ll n,k;

ll lowbit(ll k)
{
    return k&(-k);
}

void update(ll p,ll k)
{
    while(p<=n)
    {
        c[p]+=k;//����ʱ���Ͻڵ��ֵҪ�����棬��b������Ϊ�ڵ�λ��Ҫ�ֿ�
        p+=lowbit(p);
    }
}

ll sum(ll p)
{
    ll ans=0;
    while(p>0)
    {
        ans+=c[p];
        p-=lowbit(p);
    }
    return ans;
}

int main()
{
    while(scanf("%lld%lld",&n,&k)!=EOF)
    {
        memset(c,0,sizeof(c));//�����״����
        for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        b[i]=a[i];
    }
    sort(b+1,b+1+n);
    int tot=unique(b+1,b+1+n)-b-1;
    for(int i=1;i<=n;i++)
    {
        a[i]=lower_bound(b+1,b+1+tot,a[i])-b;
    }
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        update(a[i],1);
        ans+=(i-sum(a[i]));
    }
    if(ans<=k) printf("0\n");
    else
    {
        printf("%lld\n",ans-k);
    }
    }
    return 0;
}

