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
        if(power&1)//����
        {
            result=result*base;
            result%=p;
        }
        power>>=1;//������ż��Ҫ/2��ż��Ҫ������*2
        base=base*base;
        base=base%p;//һ��Ҫע��ȡ������������
    }
    return result;

}

int main() {


    cin >> base >> power>>p;

    cout<<base<<'^'<<power<<" mod "<<p<<'=';
    cout << fun(base, power)%p << endl;

    return 0;

}

