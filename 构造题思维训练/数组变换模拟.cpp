/*为了避免更多的重复循环，所以从后面开始倒推*/
#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
#define int long long
const int maxn=2e5+10;

int t,n,m;
int a[maxn];
string s;
int ans[maxn];
int cnt;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }

        cin>>s;
        int l=1,r=n;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='L') l++;//技巧，记录下最后的位置
            else r--;
        }
        int sum=1;
        cnt=n;
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='L')
            {
                l--;
                sum=(sum*(a[l]%m))%m;
                ans[cnt--]=sum;
            }
            else
            {
                r++;
                sum=(sum*(a[r]%m))%m;
                ans[cnt--]=sum;
            }
        }
        for(int i=1;i<=n;i++)
            cout<<ans[i]<<' ';
        cout<<endl;
    }
}

