#include<iostream>
#include<cmath>
using namespace std;
typedef long long LL;

LL base, power,p;
LL fun(LL base,LL power)
{
    LL result=1;
    while(power>0)
    {
        if(power&1)//奇数
        {
            result=result*base;
            result%=p;
        }
        power>>=1;//无论奇偶都要/2，偶数要将底数*2
        base=base*base;
        base=base%p;//一定要注意取余数！！！！
    }
    return result;

}

int main() {


    cin >> base >> power>>p;

    cout<<base<<'^'<<power<<" mod "<<p<<'=';
    cout << fun(base, power)%p << endl;

    return 0;

}

