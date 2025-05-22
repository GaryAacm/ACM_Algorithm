#include<bits/stdc++.h>
using namespace std;
const int INF=1e9;
const int maxn=305;

int n,m,grap[maxn][maxn],pre[maxn],t;//����Ǹ���¼ǰ���ڵ�

int bfs(int s,int t)//�ҵ�һ��·���������
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
        if(u==t) break;//�����յ㣬�ҵ�һ��·��
        for(int i=1;i<=n;i++)
        {
            if(i!=s&&grap[u][i]>0&&pre[i]==-1)
            {
                pre[i]=u;
                Q.push(i);
                flow[i]=min(flow[u],grap[u][i]);//�ҵ���С�ĵ㣬���½ڵ�����
            }
        }

    }
    if(pre[t]==-1) return -1;//û��·��
    return flow[t];
}

int maxflow(int s,int t)//�������������
{
    int maxflow=0;
    while(1)
    {
        int flow=bfs(s,t);

        if(flow==-1) break;//û�б�
        int cur=t;//��¼·�����������
        while(cur!=s)//���˸��·����
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

int order=0;
int main()
{
    //freopen("D:\\�㷨����\\ͼ��\\�����\\in.txt","r",stdin);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        memset(grap,0,sizeof(grap));
        for(int i=0;i<m;i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            grap[u][v]+=w;
        }

        printf("Case %d: %d\n",++order,maxflow(1,n));
    }

    return 0;
}

