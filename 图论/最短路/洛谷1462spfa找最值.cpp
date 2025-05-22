#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9+10;
const int NUM=5e5+5;

struct Edge
{
    int to,next,wei;
}edge[NUM<<1];

int n,m,cnt,t,u,v,w,b;
int head[NUM],dis[NUM],Neg[NUM],pre[NUM],cost[NUM];
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

bool spfa(int x)
{
    if(x<cost[1]) return false;
    for(int i=1;i<=n;i++)
    {
        dis[i]=INF;
        inq[i]=false;
    }
    dis[1]=0;
    queue<int> Q;
    Q.push(1);//起点入队

    inq[1]=true;

    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();

        inq[u]=false;//出队
        for(int i=head[u];~i;i=edge[i].next)
        {
            int v=edge[i].to;
            int w=edge[i].wei;

            if(dis[u]+w<dis[v]&&!inq[v]&&cost[v]<=x)//小于距离的才能更新
            {
                dis[v]=dis[u]+w;
                inq[v]=true;
                Q.push(v);

            }
        }
    }
    if(dis[n]>b) return false;
    else return true;

}

//----------------------
int main()
{
    cin.tie(0);
    cout.tie(0);
    //freopen("C:\\Users\\asus\\Desktop\\in.txt","r",stdin);
    init();
    cin>>n>>m>>b;
    int r=0;
    for(int i=1;i<=n;++i)
    {
        cin>>cost[i];
        r=max(cost[i],r);
    }

    for(int i=1;i<=m;++i)
    {
        cin>>u>>v>>w;
        if(u==v) continue;
        addedge(u,v,w);
        addedge(v,u,w);
    }
    int l=max(cost[1],cost[n]);

    int ans=0;
    while(l<=r)
    {
        int mid=(l+r)>>1;

        if(spfa(mid)){
            ans=mid;
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    if(!spfa(INF)) cout<<"AFK";
    else cout<<ans<<endl;
}

