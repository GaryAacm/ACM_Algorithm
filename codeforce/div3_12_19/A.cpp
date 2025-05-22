#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
int t,n;
char s[501];
int a[501];
int main()
{
    cin>>t;
    while(t--)
    {
        memset(a,0,sizeof(a));
        cin>>n;
        for(int i=1;i<=n;++i)
        {
            cin>>s[i];
            a[s[i]-'A']++;
        }
        int ans=0;
        for(int i=0;i<26;i++)
        {
            if(a[i]>=i+1) ans++;
        }
        cout<<ans<<endl;
    }
}
