#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn=2e5+10;
ll t,n,k;
ll a[maxn];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n;
        ll sum=0;
        ll minn=1e9+1,minn2=1e9+1;
        for(int i=1;i<=n;i++)
        {
            cin>>k;
            for(int j=1;j<=k;j++)
            {
                cin>>a[j];
            }
            sort(a+1,a+1+k);
            minn=min(minn,a[1]);
            minn2=min(minn2,a[2]);//�ҵ���Сֵ��С���Ǹ�������С�ļ���ȥ
            sum+=a[2];//ÿ�ΰ���Сֵ�ó��������ϴ�Сֵ
        }
        cout<<sum-minn2+minn<<endl;
    }
}
