#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
ll n,a[maxn];
ll ans=0;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    //freopen("D:\\算法进阶\\洛谷比赛\\in.txt","r",stdin);
    cin>>n;

    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        ans^=a[i];
    }
    //cout<<ans<<endl;
    if(ans==0)
        cout<<0<<' '<<0<<endl;
    else
        cout<<ans<<' '<<0<<endl;

    return 0;
}
