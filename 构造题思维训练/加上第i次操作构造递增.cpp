#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn=2e5+10;

int t,n,a[maxn],ans[maxn],s[maxn];

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        s[i]=a[i]-a[i-1];//��¼��ֵ
        ans[i]=0;
    }
    for(int i=1;i<=n;i++)
    {
        if(s[i]>0) continue;//�Ѿ�����
        ans[a[i-1]]=i;
    }

    for(int i=1;i<=n;i++)
    {
        if(!ans[i]) ans[i]=1;//��Ӱ�쵥����
    }
    for(int i=1;i<=n;i++)
    {
        cout<<ans[i]<<' ';
    }
    cout<<endl;

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}
