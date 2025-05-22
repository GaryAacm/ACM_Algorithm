#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn=5e3+10;
int T,n,t,m;
ll x[maxn],hit[maxn];
struct node
{
    ll val,id;
}a[maxn];

bool cmp(node x,node y)
{
    return x.val<y.val;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>T;
    while(T--)
    {
        cin>>n>>t>>m;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i].val;
            a[i].id=i;
        }
        memset(x,0,sizeof(x));
        for(int i=1;i<=m;i++)
        {
            int tmp;
            cin>>tmp;
            x[tmp]++;
        }
        for(int i=1;i<=n;i++)//计算损坏值
        {
            hit[i]=x[i]*2;
            a[i].val-=hit[i];
        }
        //sort(hit+1,hit+1+n);
        sort(a+1,a+1+n,cmp);
        ll ans=0;
        for(int i=n;i>=1;i--)
        {
            if(a[i].val>0)
            {
                ans++;
                continue;
            }
            else
            {
                if(t==0) break;
                while(a[i].val<=0)
                {
                    a[i].val++;
                    t--;
                    if(t==0) break;
                }
                //cout<<"变化："<<a[i].val<<endl;
                if(a[i].val>0)
                {
                    ans++;
                }

            }
        }
        cout<<ans<<endl;
    }
}
