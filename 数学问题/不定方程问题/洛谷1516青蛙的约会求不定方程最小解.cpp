#include<iostream>
typedef long long ll;
using namespace std;

ll x,y,m,n,l;
ll ans;
ll x1,y11;
ll extend_gcd(ll a,ll b,ll &x1,ll &y11)//得到的x1和y11为一组特解
{
    if(b==0)
    {
        x1=1;
        y11=0;
        return a;//表示递归到最后，返回
    }

    ans=extend_gcd(b,a%b,x1,y11);
    ll temp=x1;
    x1=y11;
    y11=temp-(a/b)*y11;
    return ans;
}


int main()
{
    cin>>x>>y>>m>>n>>l;
    ll a=n-m;
    ll b=x-y;
    if(a<0)
    {
        a=-a;
        b=-b;
    }

    extend_gcd(a,l,x1,y11);
    if(b%ans!=0) cout<<"Impossible"<<endl;
    else
    {
        cout<<((x1*(b/ans))%(l/ans)+(l/ans))%(l/ans)<<endl;//放大回原来的倍数
    }
    return 0;
}

