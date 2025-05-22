#include<iostream>
#include<cmath>
using namespace std;
typedef long long LL;
LL fun(LL base,LL power)
{
    LL result=1;
    while(power>0)
    {
        if(power&1)//奇数
        {
            result=result*base%100000;
        }
        power>>=1;//无论奇偶都要/2，偶数要将底数*2
        base=base*base%100000;
    }
    return result;

}

int main() {
    LL base, power;
    while (true) {
        cin >> base >> power;
        if (base == 0 && power == 0) break;
        cout << fun(base, power) << endl;
    }
    return 0;

}

