#include<bits/stdc++.h>
using namespace std;

double a;

int main()
{
    cin>>a;
    //double x1=pow((a+1)/10,2);
    double x2=pow(a/10,2);
    //double x3=min(x1,x2);

    int x3=(int)x2;
    if(x2-(double)x3<1e-15)
        cout<<x3<<endl;

    else cout<<x3+1<<endl;

}
