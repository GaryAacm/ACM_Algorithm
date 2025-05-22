#include<bits/stdc++.h>
using namespace std;

int n;
double a[100005];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    double k=a[1];
   // cout<<k<<endl;
    for(int i=1;i<=n;i++)
    {
        a[i]=abs(a[i]-k);
    }
    /*for(int i=1;i<=n;i++)
    {
        cout<<a[i]<<endl;
    }*/
    bool flag=true;
    for(int i=2;i<=n;i++)
    {
        if(a[i]-a[i-1]<=1e-6)
        {

            flag=false;
            break;
        }
    }
    if(flag) cout<<"lovely"<<'\n'<<k;
    else cout<<"pigeon";

    return 0;
}
