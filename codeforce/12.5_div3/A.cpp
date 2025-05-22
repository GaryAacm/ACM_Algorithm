#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;

int t,pos;
char c;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>c>>pos;
        for(int i=1;i<=8;i++)
        {
            if(i==pos) continue;
            else
            {
                cout<<c<<i<<endl;
            }
        }
        char s='a';
        while(s!='i')
        {
            if(s!=c)
                cout<<s<<pos<<endl;
            s=char(s+1);
        }
    }

    return 0;
}

