#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=10005;
vector<int> G[maxn];
int cnt=0,dfn;
int mindd[maxn];
int low[maxn],top=0;//low是能够返回的最远祖先，num是节点访问顺序
int num[maxn],scnno[maxn],stacked[maxn];//scnno用来记录当前点属于哪个连通块
int n,m,u,v,p;
int in[maxn],out[maxn];
map<int,int> mapp;
int cost[maxn];
int last=50000;
void dfs(int u)
{
    num[u]=low[u]=++dfn;//第一个点作为访问顺序
    stacked[top++]=u;
    for(int i=0;i<G[u].size();i++)
    {
        int v=G[u][i];
        if(!num[v])
        {
            dfs(v);
            low[u]=min(low[u],low[v]);//往上更新回退边
        }
        else if(!scnno[v])//没有加进联通块
            low[u]=min(low[u],num[v]);

    }
    if(low[u]==num[u])//当前连通块的点的祖先
    {
        cnt++;
        int mink=1e9;
        while(1)
            {
                int v=stacked[--top];//出栈，表示同一个区间元素
                scnno[v]=cnt;
                //cout<<cnt<<endl;
                mink=min(mink,v);
                if(u==v) break;//找到栈底的那个点
            }
            mindd[cnt]=mink;//找到区间里面最小的id
    }
}

void Tarjan(int n)
{
    cnt=0;
    for(int i=0;i<=n;i++)
        cost[i]=1e9;
    top=dfn=0;
    memset(num,0,sizeof(num));
    memset(scnno,0,sizeof(scnno));
    memset(low,0,sizeof(low));
    for(int i=1;i<=n;i++)
    {
        if(!num[i])
            dfs(i);
    }

}

void solve(int u)//求出缩点后新图的入度和出度
{
    for(int i=0;i<G[u].size();i++)
    {
        int v=G[u][i];
        if(scnno[u]!=scnno[v])
        {
            if(mapp[u]||in[scnno[u]]) cost[scnno[u]]=min(mapp[u],cost[scnno[u]]),in[scnno[v]]=1;
        }

    }

}

signed main()
{
    //freopen("C:\\Users\\asus\\Desktop\\P1262_2.in","r",stdin);
    int minn=1e9;
    cin>>n>>p;
    for(int i=1;i<=p;i++)
    {
        cin>>u>>v;
        mapp[u]=v;
        minn=min(minn,v);
    }
    for(int i=0;i<=n;i++)
    {
        G[i].clear();
    }
    cin>>m;
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
    }
    Tarjan(n);
    for(int i=1;i<=n;i++) solve(i);
    int ans=0,id=1e9;
    bool f=true;
    for(int i=1;i<=cnt;i++)
    {
        if(!in[i])//入度为0的点，一定要收买里面的一个间谍
        {
            if(cost[i]==1e9)//入读为0的点有人不被收买
            {
                f=false;
                id=min(id,mindd[i]);
                //cout<<i<<' '<<id<<' '<<mindd[i]<<endl;
                //break;
            }
            if(f) ans+=cost[i];
        }
    }
    if(cnt==1)
    {
        cout<<"YES"<<endl;
        cout<<minn<<endl;
    }
    else
    {
        if(f)
        {
            cout<<"YES"<<endl;
            cout<<ans;
        }
        else
        {
            cout<<"NO"<<endl;
            cout<<id<<endl;
        }
    }
    return 0;
}

/*#include<iostream>
#include<cstdio>
#include<vector>
#include<stack>
#include<algorithm>
#define INF (int)0x3f3f3f3f
#define maxn 10010
using namespace std;
int n,p,num,cnt;   // num是tarjan的时间戳   cnt在缩点时维护强连通分量的个数
int w[maxn],dfn[maxn],low[maxn];
int mi[maxn],k[maxn],minid[maxn];    //   缩点后 pw每个强连通分量的最小花费  k[i]表示i点属于哪个强连通分量
bool vis[maxn],flag[maxn][maxn],ru[maxn];    //  vis数组表示i是否在数组里  flag表示i j两个强连通分量有没有连边
vector<int> v[maxn];
stack<int> s;
void tarjan(int x)    //  标准的tarjan
{
	low[x]=dfn[x]=++num;
	s.push(x);
	vis[x]=true;
	for(int i=0;i<v[x].size();i++)
	{
		int ed=v[x][i];
		if(!dfn[ed])
		{
			tarjan(ed);
			low[x]=min(low[x],low[ed]);
		}
		else if(vis[ed]) low[x]=min(low[x],dfn[ed]);
	}
	if(dfn[x]==low[x])    //  x是一个关键点
	{
		int minw=INF,lk=INF,t;
		cnt++;
		while(1)
		{
			t=s.top();
			s.pop();
			vis[t]=false;
			minw=min(minw,w[t]);     //   取这个强连通分量的最小花费
			lk=min(lk,t);
			k[t]=cnt;
			if(t==x) break;
		}
		minid[cnt]=lk;
		mi[cnt]=minw;
	}
}
int main()
{
	scanf("%d%d",&n,&p);           //  n个间谍  有p个间谍愿意被收买
	for(int i=1;i<=n;i++) w[i]=INF; // 先初始化 如果i号间谍开价为INF说明他不能被收买
	int a,b;
	for(int i=1;i<=p;i++)
	{
		scanf("%d%d",&a,&b);       //  a号间谍愿意被收买
		w[a]=b;     		   //   w数组代表每个间谍愿意被收买的金额
	}
	int r;
	scanf("%d",&r);
	for(int i=1;i<=r;i++)
	{
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i]) tarjan(i);    	 	//   tarjan缩点
	for(int i=1;i<=n;i++)  // 注意！！事实上我没有缩点建新图的操作！因为不需要
	{
		for(int j=0;j<v[i].size();j++)
		{
			int ed=v[i][j];
			if(k[i]==k[ed]||flag[k[i]][k[ed]]) continue; // 同一个强连通分量的点直接跳过 或者两个强连通分量已经判断过了
			flag[k[i]][k[ed]]=true;
			if(ru[k[i]]||mi[k[i]]!=INF) ru[k[ed]]=true;    //   重点！如果i点所在强连通分量不能被贿赂 或！不能被其他点到达 他们所指向的点不记录有入度
		}
	}
	int id=INF,all=0;    //   如果不符合题意 找到的最小编号id
	bool f=false;
	for(int i=1;i<=cnt;i++)
	{
		if(ru[i]) continue;   //  有入度的点跳过
		if(mi[i]==INF)    //  这个强联通分量不能买 说明整张图就无解了
		{
			f=true;
			id=min(id,minid[i]);   // 找到最小编号
		}
		if(!f) all+=mi[i];
	}
	if(f) printf("NO\n%d",id);
	else printf("YES\n%d",all);
	return 0;
}*/
