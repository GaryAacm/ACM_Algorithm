#include<bits/stdc++.h>
using namespace std;

int t,n;
string s;
int main()
{
    //freopen("D:\\算法进阶\\codeforce\\Round911div2\\in.txt","r",stdin);
    cin>>t;
    while(t--)
    {
        cin>>n;
        cin>>s;
        int flag=0,same=0;
        int cnt=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='.')
            {
                same=1;//不会全部阻塞
                cnt++;
            }
            if(i<s.length()-2)
            {
                if(s[i]=='.')
                {
                    if(s[i]==s[i+1]&&s[i]==s[i+2])
                        flag=1;
                }
            }
        }
        if(!same) cout<<'0'<<endl;
        else if(flag) cout<<'2'<<endl;
        else
            cout<<cnt<<endl;
    }
    return 0;
}
