#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+10;
//�ṩ��һ��˼·�����Ǵ����������У�Ȼ�����ߣ���û�������ıߵĴ���
int t,n,m,a[maxn];
int x,y;
void init()
{
    for(int i=1;i<=n;i++) a[i]=n;//��ʼ�ܹ�������յ���n
}

void solve()
{
    cin>>n>>m;
    init();
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y;
        if(x>y) swap(x,y);
        a[x]=min(a[x],y-1);//���µ���ĵ�
    }
    for(int i=n-1;i>=1;i--)
    {
        a[i]=min(a[i],a[i+1]);//ǰ���ȥ���˺���ĵ�

    }

    int ans=0;
    for(int i=1;i<=n;i++)
    {
        ans+=a[i]-i+1;
    }
    cout<<ans<<endl;
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
