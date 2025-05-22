#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn=2e5+10;


int t,n;
int a[100];
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        int ans=0;
        bool f=false;
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==1&&!f)//¿ªÍ·µÄ1
            {
                f=true;

            }
            if(a[i]==0&&f)
            {
                cnt++;
            }
            if(a[i]==1&&cnt)
            {
                ans+=cnt;
                cnt=0;
            }

        }
        cout<<ans<<endl;
    }
}
