#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int n;
ll a[maxn],ans=0;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    //freopen("D:\\算法进阶\\洛谷比赛\\in.txt","r",stdin);
    cin>>n;
    for(int i=0;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        if((a[i]>0&&a[i+1]<0)||(a[i]<0&&a[i+1]>0))
            ans++;
    }

    cout<<ans<<endl;
    return 0;

}
