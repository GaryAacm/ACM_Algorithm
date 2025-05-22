#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn=1e5+10;

int n,q;
string s,ss;
int a[3];
int op[maxn],tmp;
int main()
{
    cin>>n>>q;
    cin>>s>>ss;
    for(int i=0;i<ss.length();i++)
    {
        if(ss[i]=='1') a[1]++;
        else a[2]++;
    }

    if(a[1]%2==0&&a[2]%2==0) cout<<s<<endl;
    else
    {
        if(a[1]%2==0&&a[2]%2==1)//·´×ª
        {
            for(int i=0;i<n;i++)
            {
                if(s[i]=='0') cout<<1;
                else cout<<0;
            }
            cout<<endl;
        }
        else if(a[1]%2==1&&a[2]%2==0)//·­×ª
        {
            for(int i=n-1;i>=0;i--)
                cout<<s[i];

            cout<<endl;
        }
        else
        {
            for(int i=n-1;i>=0;i--)
            {
                if(s[i]=='0') cout<<1;
                else cout<<0;
            }
            cout<<endl;
        }

    }
}
