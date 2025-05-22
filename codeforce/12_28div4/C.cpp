#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
typedef long long ll;
ll sum=0;
ll t,n;
ll a[maxn];
ll ans[maxn];

int main()
{
    cin.tie(0);
    cout.tie(0);
    //freopen("C:\\Users\\asus\\Desktop\\in.txt","r",stdin);
    cin>>t;

    while(t--){
        cin>>n;
        sum=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            sum+=a[i];
        }
        ll k=sqrt(sum);
        if(k*k==sum) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;

    }
}
