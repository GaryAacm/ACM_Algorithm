#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn=2e5+10;

string s1,s2;
int t;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>s1>>s2;
        bool f=false;
        for(int i=0;i<s1.length()-1;i++)
        {
            if(s1[i]=='0'&&s1[i+1]=='1'&&s2[i]=='0'&&s2[i+1]=='1')
            {
                f=true;
                break;
            }
        }
        if(f) cout<<"Yes"<<'\n';
        else
            cout<<"No"<<'\n';
    }
}
