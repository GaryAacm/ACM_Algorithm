#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
#define int long long
const int maxn=2e5+10;

int t,n,a[maxn];


//思路是找到互补的情况填入，一段一段填入，找到当前可以达到的最大的
//找到当前数可以达到最大的一段一段递归处理
void solve(int x)
{
    if(x<0) return ;
    int k=ceil(sqrt(x));
    k=k*k;//找到当前可以达到的最值
    solve(k-x-1);//在这一段区间里面塞
    //for(int i=x;i>=k-x;i--) cout<<i<<' ';
    int tmp=x;
    for(int i=k-x;i<=x;i++)
    {
        a[i]=tmp--;
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n;
        solve(n-1);//从0开始
        for(int i=0;i<n;i++)
            cout<<a[i]<<' ';
        cout<<'\n';
    }
}
