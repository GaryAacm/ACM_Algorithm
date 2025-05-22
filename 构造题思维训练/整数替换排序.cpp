/*观察数学问题，主要在于找到交集*/
#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn=2e5+10;

int t,n;
int a[maxn];

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);

        }
        int l=0,r=2e9;
        for(int i=1;i<n;i++)
        {
            if(a[i]<a[i+1])
            {
                r=min(r,(a[i]+a[i+1])/2);
            }
            if(a[i]>a[i+1])
                l=max(l,(a[i]+a[i+1]+1)/2);
        }
        if(l<=r) printf("%d\n",l);
        else printf("-1\n");
    }
}
