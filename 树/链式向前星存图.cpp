#include<iostream>
using namespace std;

struct Edge  //每一个edge代表一条边，数组序号代表编号
{
	int next;  //上一个同起点的边的序号
	int to;  //这条边指向的点
	int w;  //这条边的长度
};

Edge edge[101];  //先定义个101条边

int head[101];  //head[i],代表以i为起点的边的最大序号是head[i]，随着数组的输入而更新

int cnt = 1;   //工具变量，记录边的序号，顺便(真的是顺便，这个功能非必要)记录了有几条边，add函数用一次自加一次

void add(int u, int v, int w)  //输入从u到v的长度为w的边
{
    edge[cnt].w = w;  //第cnt条边长为w
    edge[cnt].to = v;  //第cnt条边指向点v
    edge[cnt].next = head[u];  //上一条以u为起点的最大序号的边的序号是head[u]，每一条边都记录下了上一个同起点的边的序号，用next
    head[u] = cnt++;  //现在以u为起点的最大序号的边的序号是cnt了
}

int main()
{
    for (int i = 0; i < 101; i++)  //把所有head初始化为-1，代表以i为起点的序号最小的边的next值为-1
        head[i] = -1;

    int m, n;  //m个点，n条边
    cin >> m >> n;

    for (int i = 1; i <= n; i++)  //边的输入
    {
        int u, v,w;
        cin >> u >> v>>w;
        add(u, v, w);
    }

    for (int i = 1; i <= m; i++)  //输出每个以i为起点的所有线
    {
        for (int j = head[i]; j != -1; j=edge[j].next)  //从以i为起点的最大序号边开始，通过每条边的next递推从而依次按边的序号从大到小输出边，到j=-1就说明输出完了
        {
            cout <<"这一条边是  "<< i << " --->" << edge[j].to << "  长度为" << edge[j].w << endl;
        }
    }
    return 0;
}
