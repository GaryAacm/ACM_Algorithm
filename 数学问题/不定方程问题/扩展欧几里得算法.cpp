#include<bits/stdc++.h>
using namespace std;

void extend_gcd(int a,int b,int &x,int &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return ;//表示递归到最后，返回
    }

    extend_gcd(b,a%b,x,y);
    int temp=x;
    x=y;
    y=temp-(a/b)*y;
}
