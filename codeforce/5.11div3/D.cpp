#include<bits/stdc++.h>
using namespace std;
#define int long long
using ll = long long;
const int maxn=2e5+10;
int t,n,k,pb,ps;
int p[maxn],a[maxn];
//����ѩ����һ��
void solve()
{
    cin>>n>>k>>pb>>ps;
    for(int i=1;i<=n;i++)
    {
        cin>>p[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    ll rb = 0, rs = 0;
	ll sb = 0, ss = 0;
	for(int i=0;i<=min(k-1,n);i++)
    {
        rb = max(rb, sb + (k - i) * a[pb]);//ö��Ҫ��Ҫͣ��
		sb += a[pb], pb = p[pb];//sb�洢��ǰ��ֵ��pb�����߶���λ��
		rs = max(rs, ss + (k - i) * a[ps]);
		ss += a[ps], ps = p[ps];
    }
    if (rb > rs) puts("Bodya");
	else if (rb == rs) puts("Draw");
	else puts("Sasha");
}

signed main()
{
    cin>>t;
    while(t--)
    {
        solve();
    }
}
