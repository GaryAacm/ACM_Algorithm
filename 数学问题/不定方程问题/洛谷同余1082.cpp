#include<iostream>
using namespace std;
int x,y;

int gcd(int a,int b)
{
    if(a<b)
        swap(a,b);
    return b?gcd(b,a%b):a;
}

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

int a,b;
int main()
{
    cin>>a>>b;
    extend_gcd(a,b,x,y);
    cout<<(x%(b/gcd(a,b))+b/gcd(a,b))%(b/gcd(a,b))<<endl;

    return 0;
}
