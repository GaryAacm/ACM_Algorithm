#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn=2e5+10;
int a,b,d;

int main()
{
    cin>>a>>b>>d;
    for(int i=a;i<=b;i+=d)
        cout<<i<<' ';
    return 0;
}
