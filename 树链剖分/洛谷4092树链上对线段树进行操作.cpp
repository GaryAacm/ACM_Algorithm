#include<bits/stdc++.h>
using namespace std;

const int N = 100000 + 10;

inline int read()
{
	int res=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')res=(res<<3)+(res<<1)+(ch^48),ch=getchar();
	return res;
}

struct edge{
	int next,to;
}r[N<<1];

int head[N],tot;

inline void add(int u,int v)
{
	r[++tot]=(edge){head[u],v};
	head[u]=tot;
	r[++tot]=(edge){head[v],u};
	head[v]=tot;
}

int dep[N],Size[N],fa[N],son[N],top[N],id[N],cnt;

void dfs1(int u,int father)
{
	fa[u]=father,dep[u]=dep[father]+1,Size[u]=1;
	for(int e=head[u];e;e=r[e].next)
	{
		int v=r[e].to;
		if(v==father)continue;
		dfs1(v,u);
		Size[u]+=Size[v];
		if(Size[v]>Size[son[u]])
			son[u]=v;
	}
}

void dfs2(int u,int topf)
{
	top[u]=topf;
	id[u]=++cnt;
	if(!son[u])
		return ;
	dfs2(son[u],topf);
	for(int e=head[u];e;e=r[e].next)
	{
		int v=r[e].to;
		if(v==fa[u]||v==son[u])continue;
		dfs2(v,v);
	}
}

int tree[N<<2],lazy[N<<2];
#define lson pos<<1
#define rson pos<<1|1
void pushdown(int pos)
{
	if(!lazy[pos])return ;
	int k=lazy[pos];
	lazy[pos]=0;
	tree[lson]=dep[k]>dep[tree[lson]]?k:tree[lson];
	tree[rson]=dep[k]>dep[tree[rson]]?k:tree[rson];
	lazy[lson]=dep[k]>dep[lazy[lson]]?k:tree[lson];
	lazy[rson]=dep[k]>dep[lazy[rson]]?k:tree[rson];
}

//关键在更新的思路，就是每次都更新标记了节点的子树，
//tree存储的是当前节点的标记最近的祖先，根据深度进行更新，标记节点的每次更新查询其子树的节点是否最近是自己
void update(int pos,int l,int r,int L,int R,int x)
{
	if(l>R||r<L)
		return ;
	if(l>=L&&r<=R)
	{
		tree[pos]=dep[x]>dep[tree[pos]]?x:tree[pos];
		lazy[pos]=dep[x]>dep[lazy[pos]]?x:lazy[pos];
		return ;
	}
	pushdown(pos);
	int mid=(l+r)>>1;
	if(dep[x]>dep[tree[lson]])
		update(lson,l,mid,L,R,x);
	if(dep[x]>dep[tree[rson]])
		update(rson,mid+1,r,L,R,x);

	tree[pos]=dep[tree[lson]]<dep[tree[rson]]?tree[lson]:tree[rson];
}

int query(int pos,int l,int r,int x)
{
	if(l==x&&r==x)
		return tree[pos];
	pushdown(pos);
	int mid=(l+r)>>1;
	if(x<=mid)return query(lson,l,mid,x);
	else return query(rson,mid+1,r,x);
}

int n,Q;

char opt;

int main()
{
	n=read(),Q=read();
	for(int i=1,u,v;i<n;i++)
		u=read(),v=read(),add(u,v);
	dfs1(1,0),dfs2(1,1);
	update(1,1,n,id[1],id[1]+Size[1]-1,1);
	int num;
	while(Q--)
	{
		cin>>opt;
		num=read();
		if(opt=='Q')
			printf("%d\n",query(1,1,n,id[num]));
		if(opt=='C')
			update(1,1,n,id[num],id[num]+Size[num]-1,num);
	}
    return 0;
}
