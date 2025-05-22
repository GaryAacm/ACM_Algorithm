#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

const int maxn=1e5+10;
int a[maxn];
int n;
/*void qsort(int a[],int l,int r)
{
    int i=l,j=r;
    int flag=a[(l+r)>>1];
    do
    {
        while(a[i]<flag) i++;
        while(a[j]>flag) j--;
        if(i<=j)
        {
            swap(a[i],a[j]);
            i++;
            j--;
        }
        if(i<r) qsort(a,i,r);
        if(j>l) qsort(a,l,j);

    }while(i<=j);
}*/

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(n%2==1)
       cout<<a[(n+1)/2]<<endl;
    else
        cout<<(a[(n)/2]+a[n/2+1])/2<<endl;
    return 0;
}
