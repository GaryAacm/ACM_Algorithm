#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn=2e5+10;

ll gcd(ll x,ll y)
{
    return y? gcd(y,x%y):x;
}

int t,a[maxn],n;
int mp[maxn];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;++i)
        {
            mp[i]=0;//表示没有使用的数字
        }
        a[1]=1;
        int cnt=1;
        for(int i=2;i<=n;++i){
            int sum=i;
            if(mp[sum]==0)//从最小的开始，没有使用过的数字
            {
                while(sum<=n)
                {
                    a[++cnt]=sum;
                    mp[sum]=1;
                    sum*=2;
                }
            }
        }
        for(int i=1;i<=cnt;++i){
            cout<<a[i]<<' ';
        }
        cout<<endl;
    }
}
