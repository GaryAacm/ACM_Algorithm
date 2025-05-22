#include<bits/stdc++.h>
using namespace std;
struct Eg{
	int u2,v,nxt;
}edg[1000001];
int head[1001],tot_edg;
void add_edg(int u1,int u2,int v){
	edg[++tot_edg].u2=u2;
	edg[tot_edg].v=v;
	edg[tot_edg].nxt=head[u1];
	head[u1]=tot_edg;//存边的时候存入另外需要的一种药
}

struct P{
	int cst,ans;
	bool v;
}ptn[1001];

typedef pair<int,int>pr;
priority_queue<pr,vector<pr>,greater<pr> >q;

int main(){
	int n;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>ptn[i].cst;
		ptn[i].ans=1;
		q.push(make_pair(ptn[i].cst,i));
	}

	int u1,u2,v;
	while(scanf("%d%d%d",&u1,&u2,&v)!=EOF){
		add_edg(u1,u2,v);
		if(u1==u2)continue;
		add_edg(u2,u1,v);
	}
	while(!q.empty()){
		int c=q.top().first,u=q.top().second;
		q.pop();
		if(c!=ptn[u].cst)continue;
		ptn[u].v=1;
		for(int i=head[u]; i; i=edg[i].nxt){
			int x=edg[i].u2,v=edg[i].v;
			if(ptn[x].v){
				if(ptn[v].cst>c+ptn[x].cst){
					ptn[v].ans=ptn[u].ans*ptn[x].ans;
					ptn[v].cst=c+ptn[x].cst;
					q.push(make_pair(ptn[v].cst,v));
				}
				else if(ptn[v].cst==c+ptn[x].cst){
					ptn[v].ans+=ptn[u].ans*ptn[x].ans;
				}
			}
		}
	}
	cout<<ptn[0].cst<<" "<<ptn[0].ans;
	return 0;
}
