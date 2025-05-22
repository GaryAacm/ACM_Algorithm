#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5;
int gcd(int a,int b)
{
    if(a<b)
        swap(a,b);
    return b?gcd(b,a%b):a;
}

int n;
int a,b;
int main()
{
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d%d",&a,&b);
        for(int i=2;i<=maxn;i++)
        {
            if(gcd(a,b*i)==b)
            {
                printf("%d\n",i*b);
                break;
            }
        }
    }
    return 0;
}
