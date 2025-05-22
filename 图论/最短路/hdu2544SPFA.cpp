#include<bits/stdc++.h>
using namespace std;

const int INF = INT_MAX/10;
const int NUM=1000005;

struct Edge
{
    int to,next,wei;
}edge[NUM];

int n,m,cnt;
int head[NUM],dis[NUM],Neg[NUM],pre[NUM];
bool inq[NUM];

void init()
{
    for(int i=0;i<NUM;i++)
    {
        edge[i].next=-1;
        head[i]=-1;
    }
    cnt=0;
}

void addedge(int u,int v,int w)
{
    edge[cnt].to=v;
    edge[cnt].wei=w;
    edge[cnt].next=head[u];
    head[u]=cnt++;
}

int spfa(int s)
{
    memset(Neg,0,sizeof(Neg));
    Neg[s]=1;
    for(int i=1;i<=n;i++)
    {
        dis[i]=INF;
        inq[i]=false;
    }
    dis[s]=0;
    queue<int> Q;
    Q.push(s);//起点入队

    inq[s]=true;

    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();
        inq[u]=false;//出队
        for(int i=head[u];~i;i=edge[i].next)
        {
            int v=edge[i].to;
            int w=edge[i].wei;
            if(dis[u]+w<dis[v])
            {
                dis[v]=dis[u]+w;
                pre[v]=u;//记录路径

                if(!inq[v])//更新了但是出队列了
                {
                    inq[v]=true;
                    Q.push(v);
                    Neg[v]++;
                    if(Neg[v]>n)
                    {
                        //负圈
                        return 1;
                    }
                }
            }
        }
    }
    printf("%d\n",dis[n]);//n到s的最短距离

    return 0;
}

int main()
{
    while(scanf("%d%d",&n,&m)!=EOF&&n&&m)
    {
        init();
        while(m--)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            addedge(u,v,w);
            addedge(v,u,w);
        }
        spfa(1);
    }

    return 0;
}
