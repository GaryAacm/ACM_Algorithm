#include <bits/stdc++.h>
using namespace std;
#define ll     long long
const int INF = 0x3f3f3f3f;
const int N = 250;
const int M = 6500;

int n, m, s, t;
ll ans;
ll num;
ll head[M << 1];
ll now[M << 1];
ll gap[N];
ll dep[N];
struct node
{
	ll next, to, w;
} edge[M << 1];
void add(ll u, ll v, ll w)
{
	edge[++num].next = head[u];
	edge[num].to = v;
	edge[num].w = w;
	head[u] = num;

	edge[++num].next = head[v];
	edge[num].to = u;
	edge[num].w = 0;
	head[v] = num;

}

void bfs()
{
	memset(dep, -1, sizeof(dep));//���Ǵ��յ��������û�н�����ȣ�depΪ-1�ĵ㽨�����յ����Ϊ0��
	dep[t] = 0;
	gap[0]++;//gap��¼ÿ������ж��ٵ㣬��Ҫ�����յ�����gap[0]++
	queue<int>q;
	q.push(t);
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int i = head[x]; i; i = edge[i].next)
		{
			int v = edge[i].to;
			ll w=edge[i^1].w;//������ͼ����Ҫȷ����������ߵ�ֵ�������Ƿ���ߣ�����w������
			if (dep[v] == -1&&w)
			{
				dep[v] = dep[x] + 1;//��ȼ�һ��Ȼ��gap����
				gap[dep[v]]++;
				q.push(v);
			}
		}
	}
}

ll dfs(int x, ll sum)
{
	if (x == t)
	{
		ans += sum;//ansΪ����Ŀ��
		return sum;//���յ��ˣ�Ŀǰʣ�µ�sum���Ͷ���������
	}
	ll k, res = 0;
	for (int i = now[x]; i && sum; i = edge[i].next)//now��ǰ���Ż�
	{
		now[x] = i;//�ǵø��µ�ǰ��
		int v = edge[i].to;
		ll w = edge[i].w;
		if (dep[v] == dep[x] - 1 && w)//ע�⣬�����Խ�����յ�ԽС��������dep[v] == dep[x] - 1����-1
		{
			k = dfs(v, min(w, sum));
			if (!k)continue;//k����0�����漸��û��Ҫ�˷�ʱ��
			edge[i].w -= k;
			edge[i ^ 1].w += k;
			res += k;
			sum -= k;
			if (!sum)return res;//���sum==0��˵��������Ѿ������ˣ�����������ͨ���ˣ����������ȣ�ֱ�ӷ�������
		}
	}

	gap[dep[x]]--;//��ǰ��ȵ�-1
	if (!gap[dep[x]])dep[s] = n + 1;//������ֶϲ㣬ֱ�Ӽ�֦������dfs
	dep[x]++;//x��ȼ�һ
	gap[dep[x]]++;//��Ӧ��ȵ�+1
	return res;//gap�������ٷ��أ����ڱ�������·�����������������ĵ�
}
int main()
{
	cin >> n >> m >> s >> t;
	ll u, v, w;
	num = 1;//��ʼֵnumҪ��ֵ1
	for (int i = 1; i <= m; ++i)
	{
		cin >> u >> v >> w;
		add(u, v, w);
	}
	bfs();//һ��bfs�������
	ans = 0;
	while (dep[s] < n&&dep[s]!=-1)//�п���ͼ�����Ͳ���ͨ���������޷�bfs��t����s�������ͻ���������ѭ�����������ж�������ͨ��˵
	{
		memcpy(now, head, sizeof(head));//ÿ������dfs����Ҫ���³�ʼnowֵ��head��ͬ����Ϊdinicÿ�ζ���bfs���½������Բ���ר�ų�ʼ����
		dfs(s, INF);
	}
	cout << ans << endl;
	return 0;
}
