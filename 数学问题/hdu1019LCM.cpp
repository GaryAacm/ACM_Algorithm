#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll ans;
ll gcd(ll x,ll y)//求最大公因数
{
    if(x<y)
        swap(x,y);
    return y? gcd(y,x%y):x;
}

ll lcm(ll a, ll b){
	return a / gcd(a,b) * b;
}

int n,m;
ll a[1000000];//改成数组会比开一个int型要快
int main()
{
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&m);
        for(int i=0;i<m;++i)
            scanf("%lld",&a[i]);
        int k=a[0];
        for(int i=1;i<m;i++)
        {
            k=lcm(k,a[i]);
        }
        printf("%lld\n",k);
    }
    return 0;
}
