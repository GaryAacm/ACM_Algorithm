/*思路就是一个一个判断，从最大的开始，看满不满足要求，不满足就缩短区间*/
#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn=2e5+10;
int t,n,a[maxn];
int l,r,minn,maxx;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        l=minn=1;
        r=maxx=n;
        while(l<=r)
        {
            if(a[l]==minn) {l++;minn++;}
            else if(a[l]==maxx) {l++;maxx--;}
            else if(a[r]==minn) {r--;minn++;}
            else if(a[r]==maxx) {r--;maxx--;}
            else break;
        }
        if(l>r) cout<<"-1"<<'\n';
        else cout<<l<<' '<<r<<'\n';
    }
}
