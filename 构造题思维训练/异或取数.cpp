#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn=2e5+10;
#define int long long
//��Ҫ�������˼·���⣬���Ƕ��������Σ����Ƿ����γ�����һ��ģ������߸���һ�εģ������˳�����
int t,n,k;
int visit1[maxn],a[maxn],b[maxn],visit2[maxn];
int ans_same[maxn],ans1[maxn],ans2[maxn];

void solve()
{
    memset(visit1,0,sizeof(visit1));
    memset(visit2,0,sizeof(visit2));
    map<int,int> mapp,mappb;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        mapp[a[i]]++;
    }
    int cnt=0,cnt1=0,cnt2=0;
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
        if(mapp[b[i]]==1)
        {
            ans_same[++cnt]=b[i];//��¼������ͬ����
        }
        else
            mappb[b[i]]++;
    }


    for(int i=1;i<=n;i++)
    {
        if(mapp[a[i]]==2&&!visit1[a[i]])
        {
            ans1[++cnt1]=a[i];
            visit1[a[i]]=1;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(mappb[b[i]]==2&&!visit2[b[i]])
        {
            ans2[++cnt2]=b[i];
            visit2[b[i]]=1;
        }
    }

    //cout<<"cnt2: "<<cnt2<<endl;

    if(cnt1>=k)
    {
        for(int i=1;i<=k;i++)
        {
            cout<<ans1[i]<<' '<<ans1[i]<<' ';
        }
    }
    else
    {
        for(int i=1;i<=cnt1;i++)
        {
            cout<<ans1[i]<<' '<<ans1[i]<<' ';
        }
        for(int i=cnt1*2+1;i<=2*k;i+=2)
        {
            cout<<ans_same[i-cnt1*2]<<' '<<ans_same[i-cnt1*2+1]<<' ';
        }
    }
    cout<<'\n';

    if(cnt2>=k)
    {

        for(int i=1;i<=k;i++)
        {
            cout<<ans2[i]<<' '<<ans2[i]<<' ';
        }
    }
    else
    {
        for(int i=1;i<=cnt2;i++)
        {
            cout<<ans2[i]<<' '<<ans2[i]<<' ';
        }
        for(int i=cnt2*2+1;i<=2*k;i+=2)
        {
            cout<<ans_same[i-cnt2*2]<<' '<<ans_same[i-cnt2*2+1]<<' ';
        }
    }
    cout<<'\n';

    return ;


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

