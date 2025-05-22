#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn=2e5+10;

int t,n;
int a[maxn];
int sum[maxn];
int tot=0;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n;
        tot=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            sum[i]=sum[i-1]+a[i];
            tot+=a[i];
        }
        int k=tot/n;
        bool f=true;
        for(int i=1;i<=n;i++)
        {
            if(sum[i]<k*i)
            {
                f=false;
                cout<<"No"<<'\n';
                break;
            }
        }
        if(f) cout<<"Yes"<<endl;
    }
}
