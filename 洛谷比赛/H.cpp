
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
ll n,k,p,cnt[maxn],scorce[maxn],s[maxn];
vector<ll> Sub[maxn];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    //freopen("D:\\算法进阶\\洛谷比赛\\in.txt","r",stdin);
    int num=0;
    cin>>k;
    for(int i=1;i<=k;++i)
    {
        cin>>p;
        for(int j=1;j<=p;++j)
        {
            ll temp;
            cin>>temp;
            Sub[num].push_back(temp);
        }
        ll grade;
        cin>>grade;
        scorce[num]=grade;
        num++;
    }
    cin>>n;
    ll maxnn=-1;
    for(int i=1;i<=n;++i)
    {
        cin>>s[i];
        cnt[s[i]]++;
        maxnn=max(s[i],maxnn);
    }
    ll ans=0,idx=0;

    //cout<<num<<endl;

    for(int i=0;i<num;i++)
    {
        int flag=1;
        for(int j=0;j<Sub[i].size();++j)
        {
            ll v=Sub[i][j];

            //cout<<"v是："<<v<<' '<<s[v]<<endl;
            //cout<<"idx是："<<idx<<endl;
            if(j>=1&&idx!=s[v])
            {
                flag=0;
                //cout<<flag<<endl;
                break;
            }
            idx=s[v];
            //cout<<"idx是："<<idx<<endl;
        }
        if(flag) ans=max(scorce[i],ans);
    }
    cout<<ans<<endl<<idx<<endl;

    return 0;

}
