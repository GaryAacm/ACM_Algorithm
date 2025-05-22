#include <bits/stdc++.h>

using namespace std;
const int maxn=4e4+10;
#define long long int
int n;
int a[maxn],b[maxn];
signed main()
{
    cin>>n;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i]>>b[i];//输入起点和终点
    }
    sort(a,a+n);
    sort(b,b+n);
    for(int i=0;i<n;i++)
    {
        ans+=b[i]-a[i];
        if(i+1<n)
        {
            if(a[i+1]<b[i])
                ans-=b[i]-a[i+1];
        }
    }
    cout<<ans;

}
