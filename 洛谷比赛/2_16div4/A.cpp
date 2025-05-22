#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn=2e5+10;

int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    int c1=a+b,c2=a+c,c3=b+c;
    int ans=0;
    if(c>c1) ans++;
    if(b>c2) ans++;
    if(a>c3) ans++;
    cout<<ans;
}
