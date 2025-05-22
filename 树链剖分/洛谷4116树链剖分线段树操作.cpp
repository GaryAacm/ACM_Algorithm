#include<iostream>
#include<algorithm>
#include<cstdio>
#define LSON rt<<1
#define RSON rt<<1|1
#define DATA(x) b[x].data
#define LSIDE(x) b[x].l
#define RSIDE(x) b[x].r
#define MAXN 100010
#define MAX 2147483640
using namespace std;
int n,m,c=1,d=1;
int head[MAXN],deep[MAXN],son[MAXN],fa[MAXN],top[MAXN],size[MAXN],id[MAXN],nid[MAXN];
struct node1{
	int next,to;
}a[MAXN<<1];

struct node2{
	int data,l,r;
}b[MAXN<<2];

inline int read(){
	int date=0,w=1;char c=0;
	while(c<'0'||c>'9'){if(c=='-')w=-1;c=getchar();}
	while(c>='0'&&c<='9'){date=date*10+c-'0';c=getchar();}
	return date*w;
}
inline void add(int x,int y){
	a[c].to=y;
	a[c].next=head[x];
	head[x]=c++;
	a[c].to=x;
	a[c].next=head[y];
	head[y]=c++;
}
void dfs1(int rt){
	son[rt]=0;size[rt]=1;
	for(int i=head[rt];i;i=a[i].next){
		int will=a[i].to;
		if(!deep[will]){
			deep[will]=deep[rt]+1;
			fa[will]=rt;
			dfs1(will);
			size[rt]+=size[will];
			if(size[son[rt]]<size[will])son[rt]=will;
		}
	}
}
void dfs2(int rt,int f){
	nid[d]=rt;id[rt]=d++;top[rt]=f;
	if(son[rt])dfs2(son[rt],f);
	for(int i=head[rt];i;i=a[i].next){
		int will=a[i].to;
		if(will!=fa[rt]&&will!=son[rt])
		dfs2(will,will);
	}
}
inline void pushup(int rt){
	DATA(rt)=min(DATA(LSON),DATA(RSON));
}
void buildtree(int l,int r,int rt){
	int mid;
	LSIDE(rt)=l;
	RSIDE(rt)=r;
	if(l==r){
		DATA(rt)=MAX;
		return;
	}
	mid=l+r>>1;
	buildtree(l,mid,LSON);
	buildtree(mid+1,r,RSON);
	pushup(rt);
}
void update(int l,int r,int rt){
	int mid;
	if(l<=LSIDE(rt)&&RSIDE(rt)<=r){
		if(DATA(rt)!=MAX)DATA(rt)=MAX;
		else DATA(rt)=l;
		return;
	}
	mid=LSIDE(rt)+RSIDE(rt)>>1;
	if(l<=mid)update(l,r,LSON);
	if(mid<r)update(l,r,RSON);
	pushup(rt);
}
int query(int l,int r,int rt){
	int mid,ans=MAX;
	if(l<=LSIDE(rt)&&RSIDE(rt)<=r)
	return DATA(rt);
	mid=LSIDE(rt)+RSIDE(rt)>>1;
	if(l<=mid)ans=min(ans,query(l,r,LSON));
	if(mid<r)ans=min(ans,query(l,r,RSON));
	return ans;
}
void work1(int x,int y){
	int s=MAX;
	while(top[x]!=top[y]){
		if(deep[top[x]]<deep[top[y]])swap(x,y);
		s=min(s,query(id[top[x]],id[x],1));
		x=fa[top[x]];
	}
	if(deep[x]>deep[y])swap(x,y);
	s=min(s,query(id[x],id[y],1));
	printf("%d\n",s==MAX?-1:nid[s]);
	return;
}
void work(){
	int f,x;
	while(m--){
		f=read();x=read();
		if(f==0)update(id[x],id[x],1);
		if(f==1)work1(1,x);
	}
}
void init(){
	int x,y;
	n=read();m=read();
	for(int i=1;i<n;i++){
		x=read();y=read();
		add(x,y);
	}
	deep[1]=1;
	dfs1(1);
	dfs2(1,1);
	buildtree(1,n,1);
}
int main(){
	init();
	work();
	return 0;
}
