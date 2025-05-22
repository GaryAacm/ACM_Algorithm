#include<bits/stdc++.h>
using namespace std;

const int INF = INT_MAX/10;
const int NUM=3005;

struct Edge
{
    int to,next,wei;
}edge[NUM<<1];

int n,m,cnt,t,u,v,w;
int head[NUM],dis[NUM],Neg[NUM],pre[NUM];
bool inq[NUM];

//----------------��ʼ��-----------------
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
//---------------------------�ӱ�-----------------------

void spfa(int s)
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
    Q.push(s);//������

    inq[s]=true;

    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();
        inq[u]=false;//����
        for(int i=head[u];~i;i=edge[i].next)
        {
            int v=edge[i].to;
            int w=edge[i].wei;
            if(dis[u]+w<dis[v])
            {
                dis[v]=dis[u]+w;
                pre[v]=u;//��¼·��

                if(!inq[v])//�����˵��ǳ�������
                {
                    inq[v]=true;
                    Q.push(v);
                    Neg[v]++;
                    if(Neg[v]>n)
                    {
                        //��Ȧ
                        cout<<"YES"<<endl;
                        return ;
                    }
                }
            }
        }
    }
    cout<<"NO"<<endl;
    return ;
}


int main()
{
    //freopen("D:\\�㷨����\\ͼ��\\���·\\in.txt","r",stdin);
        cin>>n>>m;
        init();
        for(int i=1;i<=m;i++)
        {
            cin>>u>>v;
            addedge(u,v,1);
            addedge(v,u,1);
        }
        spfa(1);
}
