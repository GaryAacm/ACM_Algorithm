#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#include<cstdio>
using namespace std;
const int maxx=1005;
const int inf=0x3f3f3f3f;
int dfn[maxx];
int low[maxx];
int n,m;
int root,index;
int flag[maxx];
vector<int>G[maxx];
void dfs(int u,int fa){
	index++;
	int child=0;
	dfn[u]=low[u]=index;
	for(int i=0;i<G[u].size();i++){
		int v=G[u][i];
		if(dfn[v]==0){
			child++;
			dfs(v,u);
			low[u]=min(low[u],low[v]);
			if(u!=root&&low[v]>=dfn[u]){
				flag[u]++;
			}
			if(u==root&&child>1){
				flag[u]++;
			}
		}else if(i!=fa){
			low[u]=min(low[u],dfn[v]);
		}
	}
}
int main(){
	int count=1;
	int a,b;
	while(scanf("%d",&a)){
		if(a==0)break;
		n=a;
		memset(low,0,sizeof(low));
		memset(dfn,0,sizeof(dfn));
		for(int i=0;i<=maxx;i++){
			flag[i]=1;
		}
		for(int i=0;i<=maxx;i++){
			G[i].clear();
		}
		root=1,index=1;
		scanf("%d",&b);
		n=max(n,b);
		G[a].push_back(b);
		G[b].push_back(a);

		int ans=0;
		dfs(1,root);
		int vis=0;
		cout<<"Network #"<<count++<<endl;
		for(int i=1;i<=n;i++){
			if(flag[i]>1){
				vis=1;
				cout<<"  SPF node "<<i<<" leaves "<<flag[i]<<" subnets"<<endl;
			}
		}
		if(vis==0){
			cout<<"  No SPF nodes"<<endl;
		}
		cout<<endl;
	}
	return 0;
}

