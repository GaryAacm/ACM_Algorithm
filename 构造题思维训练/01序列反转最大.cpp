#include<bits/stdc++.h>
using namespace std;
int const N=1e6+10;
int ans[N];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int T;cin>>T;
	while (T--){
		int n,k,kk=0;cin>>n>>k;string s;cin>>s;s=" "+s;
		if (!k){
			cout<<s.substr(1,n)<<'\n';
			for (int i=1;i<=n;++i) cout<<"0 ";
			cout<<'\n';continue;
		}
		for (int i=1;i<=n;++i) ans[i]=0;
		for (int i=1;i<n;++i){
		    if (s[i]=='1' && (k&1)) ans[i]=1,++kk;
		    else if (s[i]=='0' && (k&1)) ans[i]=0;
		    else if (s[i]=='0' && k%2==0) ans[i]=1,++kk;
		    else ans[i]=0;
		    if (kk==k) break;
		}
		int la=k-kk;
		ans[n]=la;
		for (int i=1;i<=n;++i)
		    if ((k-ans[i])&1){//除此之外的变化次数
		    	if (s[i]=='1') s[i]='0';
		    	else s[i]='1';
			}
		cout<<s.substr(1,n)<<'\n';
		for (int i=1;i<=n;++i) cout<<ans[i]<<' ';
		cout<<'\n';
	}
    return 0;
}
