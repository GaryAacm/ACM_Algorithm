#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+10;

int t,n,k,a[maxn];

void solve()
{
    cin>>n;
    cin>>k;
    for(int  i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(k!=4)
    {
        int ans=1e9;
        for(int i=1;i<=n;i++)//看哪个出现倍数就行，因为是质数，出现一个倍数就可以整除
        {
            int cnt=0;
            while(a[i]%k!=0)
            {
                a[i]++;
                cnt++;
            }
            ans=min(ans,cnt);
        }
        cout<<ans<<'\n';

    }
    else
    {
        int num2=0;
        for(int i=1;i<=n;i++)
        {
            int tmp=a[i];
            while(tmp%2==0)
            {
                num2++;
                tmp/=2;
            }
        }
        if(num2>=2) cout<<0<<'\n';
        else if(num2==1) cout<<1<<'\n';//把一个奇数变为偶数
        else
        {
            for(int i=1;i<=n;i++)
            {
                if(a[i]%4==3)
                {
                    cout<<1<<endl;
                    return ;
                }

            }
            cout<<2<<endl;
        }
    }
}

signed main()
{
    cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}
