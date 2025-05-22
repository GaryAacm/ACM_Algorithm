#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
int n,k;
int a[maxn];
int main()
{
    cin>>n>>k;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]>=k) ans++;
    }
    cout<<ans;
    return 0;
}
