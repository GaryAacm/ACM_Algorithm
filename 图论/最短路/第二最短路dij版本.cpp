#include<bits/stdc++.h>
#define MAX 99999999
using namespace std;

int num[5005][2];
int n,t;

//堆优化
struct edge
{
    int to;
    int cost;
    bool operator < (const edge & a) const
    {
        return a.cost < cost;
    }
};

vector<edge>g[5005];

//-------------------------dij版本-----------------------
priority_queue<edge> vis;

void dijkstra(int s)
{
    int i,j;
    for(i=1; i<=n; i++)
        num[i][0]=MAX,num[i][1]=MAX;
    num[s][0]=0;
    vis.push((edge)
    {
        s,0
    });
    while(!vis.empty())
    {
        edge node=vis.top();
        int u=node.to;//开始的顶点
        vis.pop();
        for(i=0; i<g[u].size(); i++)
        {
            edge temp=g[u][i];
            int v=temp.to;
            int wei=temp.cost;

            if(num[v][0]>=num[u][0]+wei)
            {
                num[v][0]=num[u][0]+wei;
                vis.push((edge)
                {
                    v,num[v][0]
                });
            }
            else if(num[v][1]>num[u][0]+wei)//只加入最短
            {
                num[v][1]=num[u][0]+wei;
                vis.push((edge)
                {
                    v,num[v][0]
                });
            }
            if(num[v][1]>wei+num[u][1])
                num[v][1]=wei+num[u][1];
        }
    }
}


int main()
{
    int i,j,x,y,z,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        edge tmp;

        for(i=0; i<m; i++)
        {
            scanf("%d%d%d",&x,&tmp.to,&tmp.cost);
            g[x].push_back(tmp);
            int t=tmp.to;
            tmp.to=x;
            g[t].push_back(tmp);
        }
        dijkstra(1);
        printf("%d\n",num[n][1]);
    }
    return 0;
}

