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
	memset(dep, -1, sizeof(dep));//我们从终点出发，对没有建立深度（dep为-1的点建立，终点深度为0）
	dep[t] = 0;
	gap[0]++;//gap记录每个深度有多少点，不要忘记终点这里gap[0]++
	queue<int>q;
	q.push(t);
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int i = head[x]; i; i = edge[i].next)
		{
			int v = edge[i].to;
			ll w=edge[i^1].w;//反方向建图，需要确定的是正向边的值，而不是反向边，所以w是异或的
			if (dep[v] == -1&&w)
			{
				dep[v] = dep[x] + 1;//深度加一，然后gap增加
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
		ans += sum;//ans为我们目标
		return sum;//到终点了，目前剩下的sum流就都可以算入
	}
	ll k, res = 0;
	for (int i = now[x]; i && sum; i = edge[i].next)//now当前弧优化
	{
		now[x] = i;//记得更新当前弧
		int v = edge[i].to;
		ll w = edge[i].w;
		if (dep[v] == dep[x] - 1 && w)//注意，深度是越靠近终点越小，所以是dep[v] == dep[x] - 1，是-1
		{
			k = dfs(v, min(w, sum));
			if (!k)continue;//k等于0，后面几步没必要浪费时间
			edge[i].w -= k;
			edge[i ^ 1].w += k;
			res += k;
			sum -= k;
			if (!sum)return res;//如果sum==0，说明这个点已经负荷了，不能再有流通过了，则不用提高深度，直接返回跳出
		}
	}

	gap[dep[x]]--;//当前深度点-1
	if (!gap[dep[x]])dep[s] = n + 1;//如果发现断层，直接剪枝，不再dfs
	dep[x]++;//x深度加一
	gap[dep[x]]++;//对应深度点+1
	return res;//gap操作后再返回（对于遍历完其路径后还有容量可以流的点
}
int main()
{
	cin >> n >> m >> s >> t;
	ll u, v, w;
	num = 1;//初始值num要赋值1
	for (int i = 1; i <= m; ++i)
	{
		cin >> u >> v >> w;
		add(u, v, w);
	}
	bfs();//一遍bfs建立深度
	ans = 0;
	while (dep[s] < n&&dep[s]!=-1)//有可能图本来就不连通，这样就无法bfs从t建到s，这样就会在这里死循环，所以先判断你是连通再说
	{
		memcpy(now, head, sizeof(head));//每次重新dfs，都要重新初始now值与head相同（因为dinic每次都有bfs重新建立所以不用专门初始化）
		dfs(s, INF);
	}
	cout << ans << endl;
	return 0;
}
