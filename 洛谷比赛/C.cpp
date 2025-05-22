#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,k;
int m;
int main()
{
    cin>>n>>k;
    m=pow(n,n);
    int ans=0;
    for(int i=n;i<=m;i+=10)
    {
        /*if((i%k)%n==0&&i%10==n)
        {
            ans++;
        }*/

        if((i%k)%n==0) ans++;

    }
    cout<<ans<<endl;
}
