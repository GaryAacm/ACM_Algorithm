/*这里处理相同的有一个妙处，就是交换
a，b，然后判断a是否除了gcd之后是1，是就说明相等了，是的话就把b平方求得合理答案*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,a,b;
ll gcd(ll x,ll y)//求最大公因数
{
    return y? gcd(y,x%y):x;
}

int main()
{
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        if(a>b) swap(a,b);
        ll gc=gcd(a,b);
        a/=gc,b/=gc;
        b*=a;

        if(a==1) b*=b;
        cout<<b*gc<<'\n';
    }
}
