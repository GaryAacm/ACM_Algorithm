#include<bits/stdc++.h>
using namespace std;
const int N = 510000,INF = 0x3f3f3f3f;	//ע�����ݷ�Χ
typedef pair<int,int> PII;

int e[N],ne[N],w[N],h[N],idx;	//��ʽǰ���ǽ�ͼ
int n,m,s,t,dis[N];
bool vis[N];
priority_queue<PII,vector<PII>,greater<PII> > q;	//dijkstra���ȶ����Ż�

void add(int a,int b,int c)	//�ӱߺ���
{
	e[idx] = b;
	ne[idx] = h[a];
	w[idx] = c;
	h[a] = idx++;
}

void dijkstra(int s)	//dijkstraģ��
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
				add((i-1)*n+pre,(i-1)*n+cur,ad);	//����Ҫ�Ľ�ͼ��k��ͼ����Ҫ����k�����齨ͼ��ֻ��Ҫÿ�ܵ���n�ֳ�һ�㣬�������ֶ���һά����ģ���ά����
				add((i-1)*n+cur,(i-1)*n+pre,ad);	//ͬһ��·��ÿվ֮�佨һ�������
			}
			add((i-1)*n+cur,n*m+cur,0);	//n*m������㣬������Ļ�����0
			add(n*m+cur,(i-1)*n+cur,price);	//���������Ļ����Ǹ���·�ķ���
			pre = cur;	//�洢��ǰ�㣬�������һ���㽨��
		}
	}

	dijkstra(n*m+s);	//��������㿪ʼ��
	if(dis[n*m+t] == INF)	//���������յ�
		cout << -1 << endl;
	else
		cout << dis[n*m+t] << endl;

	return 0;
}
