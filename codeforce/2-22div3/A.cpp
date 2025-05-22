#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn=100;

int t,n;
char a[maxn];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        int ans=0,k=1;
        for(int i=1;i<=n;i++)
        {
            if(a[i]=='@') ans++;
            if(a[i]=='*')
            {
                if(i+1<=n&&a[i+1]=='*') break;
            }
        }
        cout<<ans<<endl;
    }
}
