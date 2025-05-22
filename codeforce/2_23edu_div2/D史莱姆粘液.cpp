#include<bits/stdc++.h>
using namespace std;
const int N=300005;
int T,n,a[N],b[N],ans[N];
long long s[N];
void work(){
	int l,r,mid;
	scanf("%d",&n),a[n+1]=0;
	for(int i=1;i<=n;++i) scanf("%d",&a[i]),s[i]=s[i-1]+a[i],ans[i]=n;
	for(int i=n;i;--i) b[i]=a[i]==a[i+1]?b[i+1]:i+1;
	for(int i=1;i<=n;++i){
		l=b[i+1],r=n+1;
		while(l<r) s[mid=(l+r)/2]-s[i]>a[i]?r=mid:l=mid+1;
		if(l<=n) ans[i]=min(ans[i],l-i);
		if(a[i+1]>a[i]) ans[i]=1;
	}
	for(int i=1;i<=n;++i) b[i]=a[i]==a[i-1]?b[i-1]:i-1;
	for(int i=1;i<=n;++i){
		l=0,r=b[i-1];
		while(l<r) s[i-1]-s[(mid=(l+r+1)/2)-1]>a[i]?l=mid:r=mid-1;
		if(l) ans[i]=min(ans[i],i-l);
		if(a[i-1]>a[i]) ans[i]=1;
	}
	for(int i=1;i<=n;++i) printf("%d ",ans[i]==n?-1:ans[i]);
	puts("");
}
int main(){
	scanf("%d",&T);
	while(T--) work();
	return 0;
}
