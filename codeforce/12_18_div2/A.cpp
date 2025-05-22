#include<bits/stdc++.h>
using namespace std;
int t;
string s;
int a[10];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>s;
        int a1=0,a2=0;
        int i=0;
        if(s[0]=='0'&&s[1]=='0')
        {
            cout<<-1<<endl;
        }
        else
        {
            for(i=0;i<s.length()/2;i++)
        {
            a1=a1*10+s[i]-'0';
            //cout<<s[i]<<endl;
            if(s[i+1]!='0')
            {
                i++;
                break;
            }
        }
        //cout<<i<<endl;
        int k=i,flag=1;
        for(;i<s.length();i++)
        {
            //cout<<s[i]<<endl;
            if(s[k]=='0')
                flag=0;
            //cout<<s[k]<<endl;
            a2=a2*10+s[i]-'0';
        }
        //cout<<flag<<endl;
        if(flag&&a1>0&&a2>0&&a1<a2) cout<<a1<<' '<<a2<<endl;
        else cout<<-1<<endl;

        }

    }
}
