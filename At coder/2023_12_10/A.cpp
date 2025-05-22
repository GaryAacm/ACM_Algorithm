#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;

int n,s,k,sum=0;

int main()
{

    cin>>n>>s>>k;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        sum+=a*b;

    }
    if(sum<s) cout<<sum+k;
    else cout<<sum;

}
