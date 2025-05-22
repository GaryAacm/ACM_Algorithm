#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6;
int n,a[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        a[i]=MAXN;
        if(i>=11) a[i]=min(a[i],a[i-11]+1);
        if(i>=5) a[i]=min(a[i],a[i-5]+1);
        if(i>=1) a[i]=min(a[i],a[i-1]+1);
    }
    printf("%d",a[n]);
    return 0;
}
