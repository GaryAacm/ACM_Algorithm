#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn=2e5+10;

string s;
int t;

int main()
{
    int a=0,b=0;
    cin>>t;
    while(t--)
    {
        cin>>s;
        a=0;
        b=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='A') a++;
            else b++;
        }
        if(a>b) cout<<"A"<<'\n';
        else cout<<"B"<<'\n';
    }
}
