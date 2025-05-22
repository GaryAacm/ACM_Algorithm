#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+10;

int t,n;
int a[maxn];
//观察发现最小数会一直作为余数出现，所以讨论前两项相同就行
//从小到大排序是关键，因为取余数出来的ai%a2一定小于a2，后面的a1小数，取余数也会更小
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    sort(a+1,a+1+n);
    bool f = false;
    if(a[1]!=a[2]) f=true;
    else
    {
        for(int i=2;i<=n;i++)
        {
            if(a[i]%a[1]) f=true;
        }
    }

    puts(f ? "YES" : "NO");
}


signed main()
{
    cin>>t;
    while(t--)
    {
        solve();
    }
}
