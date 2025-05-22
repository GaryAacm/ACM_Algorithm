#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int t,n;
string s;
map<char,char> mapp;
void init()
{
    mapp['a']='V';
    mapp['e']='V';
    mapp['b']='C';
    mapp['c']='C';
    mapp['d']='C';


}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    //freopen("C:\\Users\\asus\\Desktop\\in.txt","r",stdin);
    cin>>t;
    init();
    while(t--){
        cin>>n;
        cin>>s;
        for(int i=0;i<n;++i){
            if(mapp[s[i]]=='C')
            {
                cout<<s[i];
            }
            else if(mapp[s[i]]=='V'){
                if(i+2<n&&mapp[s[i+1]]=='C'&&mapp[s[i+2]]=='V')
                {
                    cout<<s[i]<<'.';
                    continue;
                }
                else if(i+2<n&&mapp[s[i+1]]=='C'&&mapp[s[i+2]]=='C'){
                    cout<<s[i]<<s[i+1]<<'.';
                    i++;
                }
                else{
                    if(i+1<n)
                    {
                        cout<<s[i]<<s[i+1];
                        i++;
                    }
                    else{
                        cout<<s[i];
                    }
                }
            }
        }
        cout<<endl;
    }
}
