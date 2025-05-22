#include<bits/stdc++.h>
#define ll long long

using namespace std;
const int maxn=2e5+10;
int t,n;
int a[maxn];
void solve()
{
    for(int i=2;i<=maxn;i++)
    {
        if((a[i-1]+a[i-2])%3==0)
        {
            a[i-1]++;
        }
        int k=a[i-1]+a[i-2];
        a[i]=a[i-1]+1;
        while((a[i]+a[i-1])%3==0||3*a[i]%k==0)//保证后面和前面的满足
            a[i]++;

    }
}

int main()
{
    //freopen()
    scanf("%d",&t);
    a[0]=1;
    a[1]=3;
    solve();
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            cout<<a[i]<<' ';
        }
        cout<<endl;
    }

    return 0;
}
