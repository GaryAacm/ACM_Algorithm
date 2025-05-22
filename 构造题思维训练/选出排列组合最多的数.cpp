/*排序去重，并且令首尾可以变为相同的*/
#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn=2e5+10;

int t,n;
int a[maxn];
int p[maxn];
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
        sort(a+1,a+1+n);
        int k=unique(a+1,a+1+n)-a-1;
        int ans=0;
        for(int i=1;i<=k;i++)
        {
            int x=lower_bound(a+1,a+1+k,a[i]+n)-a-1;//要减去一，找前一位
            ans=max(ans,x-i+1);
        }
        cout<<ans<<endl;
    }

    return 0;
}
