#include<bits/stdc++.h>
using namespace std;
const int MaxN = 100010, MaxM = 500010;

struct edge
{
    int to, dis, next;
};

edge e[MaxM];
int head[MaxN], dis[MaxN], cnt;
int pre[MaxM];
int n, m, s;
//���ǵ������·��ͨ��ÿ�εĲ���������ά�������˼��Ҫ��ס
inline void add_edge( int u, int v, int d)
{
    cnt++;
    e[cnt].dis = d;
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

struct node
{
    int dis;
    int pos;
    bool operator <( const node &x )const
    {
        return x.dis < dis;
    }
};

std::priority_queue<node> q;

void init()
{
    for(int i=1;i<=n;i++)
    {
        dis[i]=0x7ffffff;
        pre[i]=0;//��¼��ǰ·������ֵ
    }
}

inline void dijkstra(int s)
{
    dis[s] = 0;
    q.push( ( node ){0, s} );
    while( !q.empty() )
    {
        node tmp = q.top();
        q.pop();
        int x = tmp.pos, d = tmp.dis;
        for( int i = head[x]; i; i = e[i].next )
        {
            int y = e[i].to;
            if( dis[y]+pre[y] > dis[x] + e[i].dis +max(pre[x],e[i].dis)) //�ü�����ֵ��ά��
            {
                dis[y] = dis[x] + e[i].dis;
                pre[y]=max(pre[x],e[i].dis);//����·�ϵ���ֵ
                q.push( ( node ){dis[y], y} );

            }
        }
    }
}



int main()
{
    cin>>n>>m;
    int u,v,w;
    init();
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v>>w;
        add_edge(u,v,w);
        add_edge(v,u,w);
    }
    dijkstra(1);

    cout<<dis[n]+pre[n]<<endl;

}
