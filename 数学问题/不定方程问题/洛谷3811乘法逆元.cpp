#include<iostream>
using namespace std;
int x,y;


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

int mod_inverse(int a,int m)
{
    extend_gcd(a,m,x,y);
    return (m+x%m)%m;
}
int n,p;
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>p;
    for(int i=1;i<=n;++i)
    {
        cout<<mod_inverse(i,p)<<endl;
    }

    return 0;
}
