/*���ﴦ����ͬ����һ��������ǽ���
a��b��Ȼ���ж�a�Ƿ����gcd֮����1���Ǿ�˵������ˣ��ǵĻ��Ͱ�bƽ����ú����*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,a,b;
ll gcd(ll x,ll y)//���������
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
