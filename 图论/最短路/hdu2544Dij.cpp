#include<bits/stdc++.h>
using namespace std;

const int INF = 1e6;
const int NUM=1e5;
struct edge
{
    int from,to,wei;
    edge(int a,int b,int c) {from=a;to=b;wei=c;}//��ʼ����ֵ
};

vector<edge> e[NUM];

struct s_node//��¼���ȶ��е�����
{
    int id;
    int n_dis;
    s_node(int b,int c)
    {
        id =b;
        n_dis=c;
    }

    bool operator < (const s_node &a) const//�����������¼
    {
        return n_dis>a.n_dis;
    }

};

int n,m;
int pre[NUM];

void dij()
{
    int s=1;
    int dis[NUM];
    bool done[NUM];//��¼�Ѿ��ҵ����·

    for(int i=0;i<=n;i++)
    {
        dis[i]=INF;
        done[i]=false;

    }

    dis[s]=0;
    priority_queue<s_node> Q;
    Q.push(s_node(s,dis[s]));//������
    while(!Q.empty())
    {
        s_node u=Q.top();
        Q.pop();
        if(done[u.id])//�Ѿ��ҵ����·
        {
            continue;
        }
        done[u.id]=true;//�˵��Ѿ�����
        for(int i=0;i<e[u.id].size();i++)
        {
            edge y=e[u.id][i];
            if(done[y.to])
            {
                continue;
            }

            if(dis[y.to]>y.wei+u.n_dis)//��ǰ�ľ�����ϱߵľ���
            {
                dis[y.to]=y.wei+u.n_dis;
                Q.push(s_node(y.to,dis[y.to]));

                pre[y.to]=u.id;//��¼ǰ���ڵ�
            }
        }
    }

    printf("%d\n",dis[n]);
}

int main()
{
    while(~scanf("%d%d",&n,&m)&&n&&m)
    {
        for(int i=0;i<=n;i++)
            e[i].clear();
        while(m--)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            e[a].push_back(edge(a,b,c));
            e[b].push_back(edge(b,a,c));
        }
        dij();
    }

    return 0;
}
