#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


map<string,string> mapp;
ll n,k;
string s,temp;
string ss;
string ssa;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("D:\\算法进阶\\洛谷比赛\\in.txt","r",stdin);
    cin>>n>>k;
    for(int i=0;i<n;++i)
    {
        cin>>s>>temp;
        mapp[s]=temp;
    }
    for(int i=0;i<k;++i)
    {
        getline(cin,s);
        cout<<s.length()<<endl;
        for(int i=0;i<s.length();i++)
        {
            ss="";
            ssa="";
            if(s[i]=='{')
            {
                while(s[i]!='}')
                {
                    ssa+=s[i++];
                }
                ss+=mapp[ssa];
            }
            else
            {
                ss+=s[i];
                //cout<<s[i]<<endl;
            }
        }
        cout<<ss<<endl;
        ss="";
        ssa="";
    }
    return 0;
}
