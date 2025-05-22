#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int n,d,h,t;
int a[maxn];

signed main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&d,&h);
        double sum=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(int i=1;i<n;i++)
        {

            if(a[i]+h<=a[i+1])
            {
                sum+=double(1.0*d*h/2);
            }
            else
            {
                int temp=a[i]+h-a[i+1];
                sum+=double(1.0*d*h/2-1.0*temp*temp*d/h/2);
            }
        }
        sum+=1.0*d*h/2;
        printf("%.8f\n",sum);
    }
}
