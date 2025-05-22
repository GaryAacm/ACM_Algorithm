#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn=2e5+10;
string s;

int main()
{
    cin>>s;
    int pos;
    int n=s.length();
    for(int i=n-1;i>=0;i--)
    {
        if(s[i]=='.')
        {
            pos=i;
            break;
        }
    }
    for(int i=pos+1;i<n;i++)
        cout<<s[i];
}
