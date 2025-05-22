#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn=2e5+10;

int t,n,a[maxn];

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(is_sorted(a+1,a+1+n)) //检查是否按非降序排序
    {
        cout<<"0"<<endl;
        return;
    }
    else
    {
        if(a[n]<a[n-1]||a[n]<0) //观察最后一个数的情况
        {
            cout<<"-1"<<endl;
            return ;
        }
        cout<<n-2<<endl;
        for(int i=1;i<=n-2;i++)//把前面全部变化
        {
            cout<<i<<' '<<n-1<<' '<<n<<' '<<endl;

        }
        return ;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}
