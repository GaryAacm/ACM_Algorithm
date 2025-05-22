/*想办法让最大和最小同时出现在间隔之内*/
#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn=2e5+10;

int n,t,k;
int a[maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>t;
    while(t--)
    {
        memset(a,0,sizeof(a));
        cin>>n>>k;
        int x=0,y=n;
        for(int i=2;i<=n;i+=k)
        {
            a[i]=++x;

        }
        for(int i=1;i<=n;i+=k)
        {
            a[i]=y--;
        }
        for(int i=1;i<=n;i++)
        {
            if(!a[i]) a[i]=++x;
        }
        for(int i=1;i<=n;++i) cout<<a[i]<<' '; //输出答案
        cout<<endl;
    }
}
