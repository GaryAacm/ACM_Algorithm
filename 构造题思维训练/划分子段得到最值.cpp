#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int t,n,k,ans,a[N],vis[N],now[N],bak;
string x,y;
main(){
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		for(int i=1;i<=n;i++){
			now[i]=now[i-1];//记录当前出现的mex
			scanf("%lld",&a[i]);
			vis[a[i]]++;
			while(vis[now[i]])now[i]++;
		}
		for(int i=0;i<n;i++)
			vis[i]=0;
		bool flag=1;
		bak=0;
		for(int i=n;i>=1;i--){
			vis[a[i]]++;
			while(vis[bak])bak++;
			if(now[i-1]==bak){
				flag=0;
				printf("2\n1 %lld\n%lld %lld\n",i-1,i,n);
				break;
			}
		}
		for(int i=0;i<n;i++)
			vis[i]=0;
		if(flag)puts("-1");
	}
	return 0;
}
