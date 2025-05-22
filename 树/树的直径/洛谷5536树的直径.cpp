#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;

struct Edge
{
	int next;  //��һ��ͬ���ıߵ����
	int to;  //������ָ��ĵ�
	int w;  //�����ߵĳ���
};

Edge edge[maxn*2];

int head[maxn];

int cnt = 1;

void add(int u, int v, int w)
{
    edge[cnt].w = w;
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}

//----------------------�����ǽ�����----------------------


int deep[maxn],maxdeep[maxn],mid,temp=0,num,path[maxn],ans[maxn];
int n,k,u,v;
bool cmp(int a,int b)
{
    return a>b;
}

//-----------��һ������,����Ķ˵�----------
void dfs1(int u,int fa)
{
    if(deep[u]>temp)
    {
        num=u;//��¼����Զ��ֱ���˵�
        temp=deep[u];
    }
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        int wei=edge[i].w;
        if(v==fa) continue;

        deep[v]=deep[u]+1;
        dfs1(v,u);
    }
}

//------------------�����ϴεĵ���һ��dfs���ص�ԭ���Ķ˵㣬��¼·��--------------
void dfs2(int u,int fa)
{
    if(deep[u]>temp)
    {

        temp=deep[u];
        num=u;
    }
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        int wei=edge[i].w;
        if(v==fa) continue;

        deep[v]=deep[u]+1;
        path[v]=u;//��¼���ڵ�
        dfs2(v,u);
    }
}

//----------------���е㿪ʼ�����-----------------------
void dfs_mid(int u,int fa)
{
    maxdeep[u]=deep[u];//��ǰ���
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        int wei=edge[i].w;
        if(v==fa) continue;
        deep[v]=deep[u]+1;
        dfs_mid(v,u);
        maxdeep[u]=max(maxdeep[u],maxdeep[v]);//�������յ����,��ʾ�������Ե������������
    }
}

int main()
{
    //freopen("D:\\�㷨����\\��\\in.txt","r",stdin);
    scanf("%d%d",&n,&k);
    for(int i=1;i<n;i++)
    {
        scanf("%d%d",&u,&v);
        add(u,v,1);
        add(v,u,1);
    }
    //temp=0;
    //memset(deep,0,sizeof(deep));
    dfs1(1,0);

    temp=0;
    memset(deep,0,sizeof(deep));
    dfs2(num,0);

//----------------�ҵ�ֱ�����е�------------------
    int mid=num;//�е�Ҫ��ʼ��������
    for(int i=1;i<=(deep[num]+1)/2;++i) mid=path[mid];//�ҵ��е�

    memset(deep,0,sizeof(deep));
    dfs_mid(mid,0);

    for(int i=1;i<=n;++i)
    {
        ans[i]=maxdeep[i]-deep[i];
    }
    sort(ans+1,ans+1+n,cmp);//�Ӵ�С
    int ans_end=0;
    for(int i=k+1;i<=n;++i) ans_end=max(ans_end,ans[i]+1);//��Ϊ��ʼ�����0

    printf("%d\n",ans_end);

    return 0;

}
