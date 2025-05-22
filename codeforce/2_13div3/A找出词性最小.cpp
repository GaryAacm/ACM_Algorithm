#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn=2e5+10;

int t,n;
int a[30];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n>=3&&n<=28)
        {
            cout<<"aa"<<char(n-2+96)<<'\n';
        }
        else if(n<=53)
        {
            cout<<'a'<<char(n-1-26+96)<<'z'<<'\n';
        }
        else
        {
            cout<<char(n-52+96)<<"zz"<<'\n';

        }
    }
}
