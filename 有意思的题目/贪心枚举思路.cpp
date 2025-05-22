/*  https://codeforces.com/contest/1914/problem/D */
#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn=1e5+10;
int t,n,k;
int main()
{
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        vector<int> a(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        vector<int> b(n);
        for(int i=0;i<n;i++)
            cin>>b[i];
        int ans=a[0]+b[0]*(k-1);
        int sum=a[0];//计算做到第i个的得到的数
        int maxx=b[0];//就是开始枚举停留在i处的时候，只做i及其前面的最大值的数
        for(int i=1;i<n;i++)
        {
            if(k<=i) break;//到不了
            maxx=max(maxx,b[i]);//只做前面最大的
            sum+=a[i];
            ans=max(ans,sum+maxx*(k-i-1));
        }
        cout<<ans<<endl;
    }
    return 0;
}
