#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int mod = 200907;

LL a,b,c,k;
LL n;

LL fun(LL base,LL power)
{
    LL result=1;
    while(power>0)
    {
        if(power&1)//奇数
        {
            result=(result*base)%mod;
        }
        power>>=1;//无论奇偶都要/2，偶数要将底数*2
        base=(base*base)%mod;
    }
    return result;

}

int main()
{
    cin>>n;
    while(n--)
    {
        cin>>a>>b>>c>>k;
        int ans=0;
        if(a+c==2*b)//算术序列
        {
            int d=b-a;
            ans=(a+(k-1)*d)%mod;
            cout<<ans<<endl;
        }
        else//快速幂处理
        {

            cout<<a*fun(b/a,k-1)%mod<<endl;
        }
    }
    return 0;
}
