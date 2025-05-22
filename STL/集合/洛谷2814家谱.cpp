#include<bits/stdc++.h>
using namespace std;
string s,s1;
map<string,string> mapp;
char c;
string finded(string x)
{
    if(x!=mapp[x])
        mapp[x]=finded(mapp[x]);
    return  mapp[x];
}

int main()
{
    cin>>c;
    while(c!='$')
    {
        cin>>s;
        if(c=='#')
        {
            s1=s;//记录父亲节点
            if(mapp[s1]=="") mapp[s1]=s;
        }
        else if(c=='+')
        {
            mapp[s]=s1;//表示儿子对应父亲
        }
        else
        {
            cout<<s<<' '<<finded(s)<<endl;
        }
        cin>>c;
    }
}
