#include<bits/stdc++.h>
using namespace std;
const int N = 510000,INF = 0x3f3f3f3f;	//注意数据范围
typedef pair<int,int> PII;

int e[N],ne[N],w[N],h[N],idx;	//链式前向星建图
int n,m,s,t,dis[N];
bool vis[N];
priority_queue<PII,vector<PII>,greater<PII> > q;	//dijkstra优先队列优化

void add(int a,int b,int c)	//加边函数
{
	e[idx] = b;
	ne[idx] = h[a];
	w[idx] = c;
	h[a] = idx++;
}

void dijkstra(int s)	//dijkstra模板
{
	memset(dis,INF,sizeof dis);
	dis[s] = 0;
	q.push({0,s});

	while(!q.empty())
	{
		int u = q.top().second;
		q.pop();
		if(vis[u])
			continue;
		vis[u] = 1;
		for(int i = h[u]; ~i;i = ne[i])
		{
			int v = e[i];
			if(dis[v] > dis[u]+w[i])
			{
				dis[v] = dis[u]+w[i];
				q.push({dis[v],v});
			}
		}
	}
}

int main()
{
	int price,ad,num,pre,cur;
	cin >> n >> m >> s >> t;
	memset(h,-1,sizeof h);
	for(int i = 1;i <= m;i++)
	{
		cin >> price >> ad >> num;
		for(int j = 0;j < num;j++)
		{
			cin >> cur;
			if(j)
			{
				add((i-1)*n+pre,(i-1)*n+cur,ad);	//最重要的建图，k张图不需要单开k个数组建图，只需要每总点数n分成一层，类似于手动用一维数组模拟二维数组
				add((i-1)*n+cur,(i-1)*n+pre,ad);	//同一线路的每站之间建一个无向边
			}
			add((i-1)*n+cur,n*m+cur,0);	//n*m层是虚层，点进虚层的花费是0
			add(n*m+cur,(i-1)*n+cur,price);	//虚层进地铁的花费是该线路的费用
			pre = cur;	//存储当前点，方便和下一个点建边
		}
	}

	dijkstra(n*m+s);	//从虚层的起点开始跑
	if(dis[n*m+t] == INF)	//答案是虚层的终点
		cout << -1 << endl;
	else
		cout << dis[n*m+t] << endl;

	return 0;
}
