#include<bits/stdc++.h>
using namespace std;
const int INF=1e9;
const int maxn=305;

int n,m,grap[maxn][maxn],pre[maxn];//最后那个记录前驱节点

int bfs(int s,int t)//找到一条路的最大流量
{
    int flow[maxn];
    memset(pre,-1,sizeof(pre));
    flow[s]=INF;pre[s]=0;
    queue<int> Q;
    Q.push(s);
    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();
        if(u==t) break;//到达终点，找到一个路径
        for(int i=1;i<=m;i++)
        {
            if(i!=s&&grap[u][i]>0&&pre[i]==-1)
            {
                pre[i]=u;
                Q.push(i);
                flow[i]=min(flow[u],grap[u][i]);//找到最小的点，更新节点流量
            }
        }

    }
    if(pre[t]==-1) return -1;//没有路径
    return flow[t];
}

int maxflow(int s,int t)//用来建立反向边
{
    int maxflow=0;
    while(1)
    {
        int flow=bfs(s,t);

        if(flow==-1) break;//没有边
        int cur=t;//记录路径建立反向边
        while(cur!=s)//回退更新反向边
        {
            int father=pre[cur];
            grap[father][cur]-=flow;
            grap[cur][father]+=flow;

            cur=father;
        }
        maxflow+=flow;
    }

    return maxflow;
}

int main()
{
    //freopen("D:\\算法进阶\\图论\\最大流\\in.txt","r",stdin);
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(grap,0,sizeof(grap));
        for(int i=0;i<n;i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            grap[u][v]+=w;
        }
        printf("%d\n",maxflow(1,m));
    }

    return 0;
}
