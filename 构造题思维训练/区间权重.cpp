/*贪心的思想，技巧就是用到了栈来处理最近的数找到最小的区间*/
#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn=2e5+10;

int t,n;
ll l[maxn],r[maxn],c[maxn];
ll dis[maxn];//存储优秀的差值
bool cmp(int x,int y)
{
    return x>y;
}
ll ans;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n;
        stack<ll> s;
        for(int i=1;i<=n;i++)
        {
            cin>>l[i];
        }
        for(int i=1;i<=n;i++)
        {
            cin>>r[i];
        }
        for(int i=1;i<=n;i++)
        {
            cin>>c[i];
        }
        int p=0;
        sort(l+1,l+1+n);
        sort(r+1,r+1+n);
        sort(c+1,c+1+n,cmp);
        for(int i=1;i<=n;i++)
        {
            //枚举r计算距离
            while(l[p]<r[i]&&p<=n)
            {
                s.push(l[p]);
                p++;
            }
            dis[i]=r[i]-s.top();
            s.pop();
        }
        ans=0;
        sort(dis+1,dis+1+n);
        for(int i=1;i<=n;i++)
        {
            ans+=dis[i]*c[i];
        }
        cout<<ans<<'\n';
    }
}
