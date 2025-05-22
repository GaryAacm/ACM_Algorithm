#include<cstdio>
#include<cstring>
const int N=(1<<17)+10,p=998244353;
int n,a[N],b[N],ta[N],tb[N];


void FWTor(int a[],int type)
{
    int i,j,k;
    for(i=1;i<=n;i++)
    for(j=0;j<(1<<n);j+=1<<i)
    for(k=0;k<(1<<i-1);k++)
    (a[j|(1<<i-1)|k]+=(a[j|k]*type+p)%p)%=p;
}


void FWTand(int a[],int type)
{
    int i,j,k;
    for(i=1;i<=n;i++)
    for(j=0;j<(1<<n);j+=1<<i)
    for(k=0;k<(1<<i-1);k++)
    (a[j|k]+=(a[j|(1<<i-1)|k]*type+p)%p)%=p;
}


void FWTxor(int a[],long long type)
{
    int i,j,k,x,y;
    for(i=1;i<=n;i++)
    for(j=0;j<(1<<n);j+=1<<i)
    for(k=0;k<(1<<i-1);k++)
    x=(a[j|k]+a[j|(1<<i-1)|k])*type%p,
    y=(a[j|k]-a[j|(1<<i-1)|k]+p)*type%p,
    a[j|k]=x,a[j|(1<<i-1)|k]=y;
}


int main()
{
    int i;scanf("%d",&n);
    for(i=0;i<(1<<n);i++)scanf("%d",&a[i]),a[i]%=p;
    for(i=0;i<(1<<n);i++)scanf("%d",&b[i]),b[i]%=p;

    //or
    memcpy(ta,a,sizeof a);
    memcpy(tb,b,sizeof b);
    FWTor(ta,1);
    FWTor(tb,1);
    for(i=0;i<(1<<n);i++)ta[i]=(long long)ta[i]*tb[i]%p;
    FWTor(ta,-1);
    for(i=0;i<(1<<n);i++)printf("%d ",ta[i]);putchar('\n');

    //and
    memcpy(ta,a,sizeof a);memcpy(tb,b,sizeof b);
    FWTand(ta,1);
    FWTand(tb,1);
    for(i=0;i<(1<<n);i++)ta[i]=(long long)ta[i]*tb[i]%p;
    FWTand(ta,-1);
    for(i=0;i<(1<<n);i++)printf("%d ",ta[i]);putchar('\n');
    //xor
    memcpy(ta,a,sizeof a);memcpy(tb,b,sizeof b);
    FWTxor(ta,1);FWTxor(tb,1);
    for(i=0;i<(1<<n);i++)ta[i]=(long long)ta[i]*tb[i]%p;
    FWTxor(ta,(p+1)>>1);
    for(i=0;i<(1<<n);i++)printf("%d ",ta[i]);putchar('\n');
    return 0;
}
