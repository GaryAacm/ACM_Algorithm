#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn=2e5+10;

int n,t,k,a,x;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>k>>x>>a;
       int tmp=a-1;
       bool f=false;
       while(tmp>=a-x)
       {
           tmp-=2;
           if(tmp+2*k==a+1)
           {
               f=true;
               break;

           }
       }
       if(f) cout<<"YES"<<'\n';
       else cout<<"NO"<<'\n';
    }
}
