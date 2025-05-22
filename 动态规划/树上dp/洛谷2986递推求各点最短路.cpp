#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e5+10;

int n,c[maxn],Q[maxn],dis[maxn],f[maxn];
int sum=0,ans=1e9;
//----------------------------
struct Edge
{
	int next;
	int to;
	int w;
};

Edge edge[maxn*2];

int head[maxn];

int cnt = 0;

void add(int u, int v, int w)
{
    edge[++cnt].w = w;
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt;
}
//----------------------------------

int dfs1(int u,int fa)
{
    int tot=0;
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v!=fa)
        {
            int s=dfs1(v,u);//������ţ������
            dis[u]+=dis[v]+edge[i].w*s;//����ȫ���ڵ㵽u�ľ���
            tot+=s;//���㵱ǰ�ڵ��ӽڵ�ţ������
        }
    }
    return Q[u]=tot+c[u];//Q��¼ţ������
}

//��¼���˵�ľ���
//���˵�ʱ������ڵ���ӽڵ㶼Ҫ���ˣ�����ڵ�Ҫǰ��
void dfs2(int u,int fa)
{
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v!=fa)
        {
            int s=edge[i].w;
            f[v]=f[u]-Q[v]*s+(sum-Q[v])*s;//���е�ԭ����1�ڵ㣬Ȼ�������ϵĻ��ˣ������ǰ��
            dfs2(v,u);
        }
    }
}

//----------------------------------



signed main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
        sum+=c[i];
    }

    int u,v,w;
    for(int i=1;i<n;i++)
    {
        cin>>u>>v>>w;
        add(u,v,w);
        add(v,u,w);
    }
    dfs1(1,1);

    dfs2(1,1);

    for(int i=1;i<=n;i++)
    {
        ans=min(ans,f[i]);
    }

    cout<<ans+dis[1]<<endl;


    return 0;
}
