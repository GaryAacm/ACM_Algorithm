/*思维问题，转化为全部正数或者负数来处理，之后保证不递减，那就分全为正数或者负数来处理、
加上前面或者后面的数*/
#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn=105+10;

pair<int,int> ans[105];
int tot;
int a[maxn];
int n,t,id,mx;

signed main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        mx=0;
        id=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            if(abs(mx)<abs(a[i]))
            {
                mx=a[i];
                id=i;
            }
        }
        tot=0;
        if(!mx)
        {
            cout<<0<<'\n';
            continue;
        }

        for(int i=1;i<=n;i++)
        {
            if(i==id) continue;
            a[i]+=mx;
            ans[++tot]={i,id};//化为全部正数或者负数
        }

        if(a[id]>0)
        {
            for(int i=2;i<=n;i++)
            {
                ans[++tot]={i,i-1};
            }
        }
        else
        {
            for(int i=n;i>1;i--)
            {
                ans[++tot]={i-1,i};
            }
        }
        cout<<tot<<'\n';
        for (int i = 1; i <= tot; i ++ )
			cout<<ans[i].first<<' '<<ans[i].second<<'\n';

    }
}
