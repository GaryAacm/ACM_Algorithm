#include<bits/stdc++.h>
using namespace std;

string s;
string s1="svpoll",s2="acoipp";
int main()
{
    cin>>s;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]>='A'&&s[i]<='Z')
        {
            s[i]+=32;
        }
    }
    if(s==s2) cout<<"Luogu";
    else if(s==s1) cout<<"Genshin";
    else cout<<"Boring";
}
