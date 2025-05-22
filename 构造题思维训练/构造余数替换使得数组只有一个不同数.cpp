/* https://codeforces.com/problemset/problem/1909/B  */
//思路就是从2开始枚举，余数只会出现0和1两种情况，如果有不同则符合要求，不符合就乘以2，
//那么余数就会有0和2或者1和3两种情况，因为原来全是0或者全是1，不断枚举下去
#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn=2e5+10;

ll t,n,k;
ll a[maxn],b[maxn],visit[maxn];

int check(ll k,ll temp)
{
    for(ll i=2;i<=n;++i)
    {
        if(a[i]%k!=temp)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    //freopen("C:\\Users\\asus\\Desktop\\in.txt","r",stdin);
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(ll i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        for(ll i=2;;i*=2)
        {
            if(check(i,a[1]%i))
            {
                cout<<i<<'\n';
                break ;
            }
        }
    }
}
