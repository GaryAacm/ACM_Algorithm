
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+10;
int a[maxn],f[maxn],g[maxn];
vector<int> fac[maxn];
signed main()
{
	for(int i=1;i<=1e5;i++)
		for(int j=i;j<=1e5;j+=i) fac[j].push_back(i);
	for(int i=1;i<=1e5;i++) reverse(fac[i].begin(),fac[i].end());
	int t;
	cin>>t;
	for(int p=1;p<=t;p++)
	{
		memset(f,0,sizeof(f));
		memset(g,0,sizeof(g));
		int n;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+n+1);
		int ans=0,tmp=0;
		for(int i=1;i<=n;i++)
		{
			ans+=tmp;
			for(auto u:fac[a[i]])
			{
				f[u]=g[u];
				for(auto v:fac[a[i]/u])
					if(v!=1) f[u]-=f[u*v];//ÈÝ³âÔ­Àí
				tmp+=u*f[u];
			}
			for(auto u:fac[a[i]]) g[u]++;
		}
		cout<<ans<<endl;
	}
}
