#include<bits/stdc++.h>
using namespace std;
int n,m,t;
void solve()
{
    cin>>n>>m;
    string s,t;
    cin>>s>>t;
    int flag=1;
    for(int i=0;i<n-1;i++)
    {
        if(s[i]==s[i+1])
        {
            flag=0;
            break;
        }
    }
    if(flag){
        cout << "Yes" << '\n';
        return;
    }
    flag=1;

    for(int i=0;i<m-1;i++)
    {
        if(t[i]==t[i+1])
        {
            flag=0;
            break;
        }
    }

    if(!flag)
    {
        cout << "No" << '\n';
        return;
    }

    //flag=1;
    char st=t[0],ed=t.back();
    for(int i=0;i<n-1;i++)
    {
        if(s[i]==s[i+1])//²åÈë
        {
            if(st==s[i]||ed==s[i+1])
                {
                    cout << "No" << '\n';
                    return ;
                }
        }
    }
    cout << "Yes" << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
	cin.tie(0);
    cin>>t;
    while(t--) solve();

    return 0;
}
