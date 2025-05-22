#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn=2e5+10;

int n;
double m;
int a[3];
int op,wei;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>op>>wei;
        a[op]=a[op]+wei;
    }
    double ans=1.0*m*a[1]/(a[1]+a[2]);
    printf("%.3f",ans);
}
