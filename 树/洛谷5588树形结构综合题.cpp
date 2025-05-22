#include<bits/stdc++.h>
using namespace std;
struct q
{
	int dep,num;
};
q w[1000010];
int x,y,n[1000010],dep[1000010],l,db[2000010],nxt[2000010],len[2000010];
int f[1000010][21],fath,o,oo,fathe[1000010],ll,h,hh;
long long a,s,sn[1000010],v[1000010],vv;
vector<int> t[1000010];
bool ff;
template <typename T> inline void read(T &x)
{
	x=0;char c=getchar();bool flg=0;
	for (;!isdigit(c);c=getchar()) if (c=='-') flg=1;
	for (;isdigit(c);c=getchar()) x=x*10+c-'0';
	if (flg) x=-x;
}
inline void write(long long x)
{
	if (x<0)
	{
		putchar('-');
		x=-x;
	}
	if (x>=10) write(x/10);
	putchar(x%10+48);
}
inline void writeln(long long x)
{
	write(x);
	puts("");
}//快读、快输
bool cmp(q p,q pp)
{
	return p.dep>pp.dep;
}//按照深度从大到小排序
void wrk(int fa,int u)
{
	dep[u]=dep[fa]+1;fathe[u]=fa;
	for (int i=0;i<=19;i++)
	f[u][i+1]=f[f[u][i]][i];
	int k=len[u];
	while (k)
	{
		if (db[k]==fa)
		{
			k=nxt[k];
			continue;
		}
		f[db[k]][0]=u;
		wrk(u,db[k]);
		sn[u]+=sn[db[k]];
		k=nxt[k];
	}
}//建树，寻找子树大小
int lca(int x,int y)
{
	if (dep[x]<dep[y]) swap(x,y);
	for (int i=20;i>=0;i--)
	{
		if (dep[f[x][i]]>=dep[y]) x=f[x][i];
		if (x==y) return x;
	}
	for (int i=20;i>=0;i--)
	{
		if (f[x][i]!=f[y][i])
		{
			x=f[x][i];
			y=f[y][i];
		}
	}
	return f[x][0];
}//寻找最近公共祖先
int main(){
	/*freopen(".in","r",stdin);
	freopen(".out","w",stdout);*/
	//ios::sync_with_stdio(false);
	read(a);
	for (int i=1;i<=a;i++)
	{
		read(n[i]);
		t[n[i]].push_back(i);
	}//读入颜色，每种颜色的节点统计
	for (int i=1;i<a;i++)
	{
		read(x);read(y);
		db[i*2-1]=y;
		nxt[i*2-1]=len[x];
		len[x]=i*2-1;
		db[i*2]=x;
		nxt[i*2]=len[y];
		len[y]=i*2;
	}//连边
	for (int i=1;i<=a;i++) sn[i]=1;//子树大小至少为1
	wrk(0,1);//建树
	for (int i=1;i<=a;i++)
	{
		l=0;
		for (int j=0;j<t[i].size();j++)
		{
			l++;
			w[l].num=t[i][j];
			w[l].dep=dep[w[l].num];
		}//将该颜色所有的点记录下编号和深度
		if (l==1)
		{
			int k=len[w[l].num];ll=0;
			while (k)
			{
				if (db[k]==fathe[w[l].num])
				{
					k=nxt[k];
					continue;
				}
				ll++;
				v[ll]=sn[db[k]];
				k=nxt[k];
			}
			vv=(sn[w[l].num]-1)*(a-sn[w[l].num])+a-1;
			for (int j=1;j<=ll;j++)
				for (int m=j+1;m<=ll;m++)
				vv+=v[j]*v[m];
			writeln(vv);
			continue;
		}//只有1个节点的情况
		if (l==0)
		{
			writeln((a*(a-1))/2);
			continue;
		}//没有节点的情况
		sort(w+1,w+l+1,cmp);//按照深度从大到小排序
		hh=0;
		for (int j=2;j<=l;j++)
		{
			fath=lca(w[1].num,w[j].num);
			if (fath!=w[j].num)
			{
				hh=j;
				break;
			}
		}//判断是否为一条链，若hh==0则为一条链
		ff=0;
		if (hh!=0)
		for (int j=3;j<=l;j++)
		{
			o=lca(w[j].num,w[1].num);oo=lca(w[j].num,w[hh].num);
			if (((o==w[j].num)||(oo==w[j].num))&&(dep[w[j].num]>=dep[fath])) continue;
			ff=1;break;
		}//判断其他的点是否与这两个点存在父子关系
		if (ff==0)
		{
			if (hh==0)
			{
				int k=w[1].num;h=w[1].num;
				while (fathe[k]!=w[l].num)
				{
					k=fathe[k];
					h=k;
				}
				writeln(sn[w[1].num]*(a-sn[w[l].num]+sn[w[l].num]-sn[h]));
			}//一条链的情况
			else writeln(sn[w[1].num]*sn[w[hh].num]);//普通情况
		}
		else writeln(0);
	}
	return 0;
}
