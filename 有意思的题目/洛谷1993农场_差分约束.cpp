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
    //freopen("D:\\�㷨����\\ͼ��\\���·\\in.txt","r",stdin);
    scanf("%d%d",&n,&m);
    init();
    int opt;
    for(int i=1;i<=n;i++) addedge(0,i,0);//����Դ��
    for(int i=1;i<=m;++i)
    {
        scanf("%d",&opt);
        if(opt==1)
        {
            scanf("%d%d%d",&u,&v,&w);
            addedge(u,v,-w);//���ݲ���ʽȷ���ߵ�˳��
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
            addedge(v,u,0);//��ȼ���0�ı�
        }

    }
    if(!spfa(0)) printf("No\n");
    else printf("Yes\n");

    return 0;

}
