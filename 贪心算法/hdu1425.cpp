#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
const int maxn=1e6+10;

int n,m;
int a[maxn];

int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    for(int i=n-1;i>=n-m;i--)
        printf("%d ",a[i]);
    }
    return 0;
}
