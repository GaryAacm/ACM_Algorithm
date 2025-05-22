#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn=2e5+10;

int T,n,k;
string s,t;
string s1,t1;

void solve()
{
    //freopen("C:\\Users\\asus\\Desktop\\tmp.txt","r",stdin);
    cin>>n>>k;
    cin>>s>>t;

    s1=s;
    t1=t;
    sort(s1.begin(),s1.end());
    sort(t1.begin(),t1.end());
    if(s1!=t1)
    {
        cout<<"NO"<<endl;
        return ;
    }
    else
    {
        int i=0;
        for(i=0;i<n;i++)
        {
            if(i+k+1>n&&i-k<0&&s[i]!=t[i])
            {
                cout<<"NO"<<endl;
                return ;
            }

        }
        cout<<"YES"<<endl;
    }

    return ;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>T;
    while(T--)
    {
        solve();
    }

    return 0;
}
