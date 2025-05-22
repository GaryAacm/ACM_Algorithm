
#include"bits/stdc++.h"
using namespace std;
const int maxn = 100010;
struct node{
	int id,v;
}a[maxn],b[maxn];
bool sb(node u,node v){
	return u.v>v.v;
}
int n,m,q,K;
map<pair<int,int>,bool>mp;
int main(){
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)
	cin>>a[i].v,a[i].id=i;
	for(int i=1;i<=m;i++)
		cin>>b[i].v,b[i].id=i;
	for(int i=1,u,v;i<=q;i++){
		cin>>u>>v;
		mp[{u,v}]=1;
	}
	sort(a+1,a+n+1,sb);
	sort(b+1,b+m+1,sb);
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(mp[{a[i].id,b[j].id}]==0){
				ans=max(ans,a[i].v+b[j].v);
				break;
			}

	cout<<ans<<endl;
}

