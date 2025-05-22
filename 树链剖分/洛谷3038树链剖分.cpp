//点权变成边权
#include<bits/stdc++.h>
using namespace std;

int n,m;
int fa[100001];//每个点的爸爸
int d[100001];//每个点的深度
int son[100001];//每个点的重儿子
int su[100001];//一个点为根节点时该子树内的点数
int top[100001];//每个点在树剖后所在链的顶端
int id[100001];//每个点在线段树里所在的位置

vector<int>g[100001];//大爱vector存图
void dfs1(int x,int f,int deep)
{
	fa[x]=f;d[x]=deep;su[x]=1;int maxs=0,i;
	for(i=0;i<g[x].size();i++)
	{
		int v=g[x][i];
		if(v!=f)
		{
			dfs1(v,x,deep+1);
			su[x]+=su[v];
			if(maxs<su[v])
			{
				son[x]=v;
				maxs=su[v];
			}
		}
	}
}
void dfs2(int x,int fafa)
{
	top[x]=fafa;id[x]=++id[0];
	if(!son[x])return;
	dfs2(son[x],fafa);
	for(int i=0;i<g[x].size();i++)
	{
		int v=g[x][i];
		if(fa[x]==v||son[x]==v)continue;
		dfs2(v,v);
	}
}


//dfs处理都一样
struct node
{
	int l,r,sum,add;
}q[400001];

void build(int p,int l,int r)
{
	q[p].l=l;q[p].r=r;
	if(l==r)return;
	build(p*2,l,(l+r)/2);
	build(p*2+1,(l+r)/2+1,r);
}
void pushdown(int p)//传递懒标记
{
	q[p*2].add+=q[p].add;q[p*2+1].add+=q[p].add;
	q[p*2].sum+=(q[p*2].r-q[p*2].l+1)*q[p].add;
	q[p*2+1].sum+=(q[p*2+1].r-q[p*2+1].l+1)*q[p].add;
	q[p].add=0;
}
void change(int p,int x,int y)
{
	if(q[p].r<x||q[p].l>y)return;
	if(q[p].l>=x&&q[p].r<=y)
	{
		q[p].sum+=q[p].r-q[p].l+1;
		q[p].add++;
		return;
	}
	pushdown(p);
	change(p*2,x,y);
	change(p*2+1,x,y);
	q[p].sum=q[p*2].sum+q[p*2+1].sum;
}

int ask(int p,int x)
{
	if(q[p].r<x||q[p].l>x)return 0;
	if(q[p].l==q[p].r)return q[p].sum;
	pushdown(p);
	return ask(p*2,x)+ask(p*2+1,x);
}//线段树的操作


int main()
{
	int x,y,i;
	char c;
	cin>>n>>m;
	for(i=1;i<n;i++)
	{
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);//存无向边
	}
	dfs1(1,0,1);
	dfs2(1,1);
	build(1,1,n);

	while(m--)
	{
		cin>>c>>x>>y;
		if(c=='P')
		{
			while(top[x]!=top[y])
			{
				if(d[top[x]]<d[top[y]])swap(x,y);
				change(1,id[top[x]],id[x]);
				x=fa[top[x]];
			}
			if(d[x]>d[y])swap(x,y);
			change(1,id[x]+1,id[y]);//用上述方法避开LCA
		}
		else
		{
			if(fa[x]==y)cout<<ask(1,id[x])<<endl;
			else cout<<ask(1,id[y])<<endl;//判断该边的边权是哪个点的点权
		}
	}
	return 0;
}
