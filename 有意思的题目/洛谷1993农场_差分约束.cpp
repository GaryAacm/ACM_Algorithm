#include<bits/stdc++.h>
using namespace std;

const int INF = INT_MAX/10;
const int NUM=5010;

struct Edge
{
    int to,next,wei;
}edge[NUM<<1];

int n,m,cnt,t,u,v,w;
int head[NUM],dis[NUM],Neg[NUM],pre[NUM];
bool inq[NUM];

//----------------初始化-----------------
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
//---------------------------加边-----------------------

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

                        return 0;
                    }
                }
            }
        }
    }
    return 1;
}


int main()
{
    //freopen("D:\\算法进阶\\图论\\最短路\\in.txt","r",stdin);
    scanf("%d%d",&n,&m);
    init();
    int opt;
    for(int i=1;i<=n;i++) addedge(0,i,0);//建立源点
    for(int i=1;i<=m;++i)
    {
        scanf("%d",&opt);
        if(opt==1)
        {
            scanf("%d%d%d",&u,&v,&w);
            addedge(u,v,-w);//根据不等式确立边的顺序
        }
        else if(opt==2)
        {
            scanf("%d%d%d",&u,&v,&w);
            addedge(v,u,w);
        }
        else
        {
            scanf("%d%d",&u,&v);
            addedge(u,v,0);
            addedge(v,u,0);//相等加上0的边
        }

    }
    if(!spfa(0)) printf("No\n");
    else printf("Yes\n");

    return 0;

}
