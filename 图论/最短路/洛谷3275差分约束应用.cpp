#include<bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;
const int NUM=1e5+10;
typedef long long ll;
struct Edge
{
    int to,next,wei;
}edge[NUM<<1];

int n,m,cnt,t,x,a,b,k;
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
        dis[i]=-INF;
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
            if(dis[u]+w>dis[v])//最长路
            {
                dis[v]=dis[u]+w;
                if(!inq[v])
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
    scanf("%d%d",&n,&k);
    init();
    for(int i=1;i<=n;i++) addedge(0,i,1);
    for(int i=1;i<=k;++i)
    {
        scanf("%d",&x);
        if(x==1)
        {
            scanf("%d%d",&a,&b);
            addedge(a,b,0);
            addedge(b,a,0);
        }
        else if(x==2)
        {
            scanf("%d%d",&a,&b);
            addedge(a,b,1);
        }
        else if(x==3){
            scanf("%d%d",&a,&b);
            addedge(b,a,0);
        }
        else if(x==4)
        {
            scanf("%d%d",&a,&b);
            addedge(b,a,1);
        }
        else if(x==5){
            addedge(a,b,0);
        }
    }
    int ans=0;
    if(!spfa(0)) printf("-1");

    else{
        for(int i=1;i<=n;++i)
        {
             ans+=dis[i];
        }

        printf("%d",ans);
    }

    return 0;
}
