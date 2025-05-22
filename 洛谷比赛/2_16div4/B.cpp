#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn=2e5+10;

double a,b,c,d,e,x,y;

int main()
{
    cin>>a>>b>>c>>d>>e>>x>>y;
    double k1=a*x+b*y,k2=c*y,k3=d*y+e;
    int pos;
    double ans=max(k1,max(k2,k3));
    if(k1==ans)
    {
        cout<<1<<' ';
        printf("%.2f",ans);
    }
    else if(k2==ans)
    {
        cout<<2<<' ';
        printf("%.2f",ans);
    }
    else
    {
        cout<<3<<' ';
        printf("%.2f",ans);
    }
}
