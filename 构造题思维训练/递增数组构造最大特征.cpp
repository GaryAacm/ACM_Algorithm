#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn=2e5+10;
int n,t,k;
int ans,dis;//��ʾ�𰸺Ͳ�ֵ
int a[50];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>k>>n;
        memset(a,0,sizeof(a));
        ans=1;
        dis=0;
        for(int i=1;i<=k;i++)
        {
            if(n-ans-dis>=k-i) ans+=dis++;//Ԥ���Ƿ񳬳���Χ
            else ans++;
            cout<<ans<<' ';
        }
        cout<<'\n';
    }
    return 0;
}
