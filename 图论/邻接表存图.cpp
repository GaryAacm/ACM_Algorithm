#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
//用结构体优化
struct edge
{
    int from,to,wei;
    edge(int a,int b,int c)//初始化,可以同时处理权值和终点问题，不需要再开另外一个vector数组
    {
        from=a;
        to=b;
        wei=c;
    }
};

vector<edge> e[maxn];

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<=n;i++)
        e[i].clear();//清空
    for(int i=1;i<=n;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        e[i].push_back(edge(a,b,c));
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<e[i].size();j++)
        {
            cout<<e[i][j].from<<endl;//这里仅展示遍历起点
        }
    }

    return 0;
}
