#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1005;

int t,n;
int a[maxn];

void solve()
{
    cin>>n;
    for(int i=2;i<=n;i++)
    {
        cin>>a[i];
    }
    int now=1000;//Ҫ����500��Ȼ����Ͳ��У���Ϊ��Ҫȡģ��
    //cout<<now<<' ';
    for(int i=1;i<=n;i++)
    {
        now+=a[i];
        cout<<now<<' ';
    }
    cout<<endl;
}

signed main()
{
    cin>>t;
    while(t--)
    {
        solve();
    }
}
