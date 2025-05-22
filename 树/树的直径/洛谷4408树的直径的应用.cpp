#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;

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


ll deep[maxn],maxdeep[maxn],mid,temp=0,num,path[maxn],ans[maxn],realdeep[maxn],deep2[maxn];
int n,k,u,v,w;
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

        deep[v]=deep[u]+wei;

        dfs1(v,u);
    }
}

//------------------�����ϴεĵ���һ��dfs���ҵ�����һ�˵���ֵ����¼·��--------------
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

        deep[v]=deep[u]+wei;
        path[v]=u;//��¼���ڵ�
        dfs2(v,u);
    }
}


void dfs3(int u,int fa)
{
    if(deep2[u]>temp)
    {

        temp=deep2[u];
        //num=u;
    }
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        int wei=edge[i].w;
        if(v==fa) continue;

        deep2[v]=deep2[u]+wei;


        dfs3(v,u);
    }
}



int main()
{
    //freopen("D:\\�㷨����\\��\\����ֱ��\\input.txt","r",stdin);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=k;i++)
    {
        scanf("%d%d%d",&u,&v,&w);
        add(u,v,w);
        add(v,u,w);
    }

    dfs1(1,0);
    int start=num;

    temp=0;
    memset(deep,0,sizeof(deep));
    dfs2(num,0);
    int ed=num;
    ll ans_end=0,temp1=0;
    ans_end=deep[ed];//���ֱ���ľ���
    //cout<<ans_end<<endl;
    //cout<<start<<' '<<ed<<endl;

    memset(deep,0,sizeof(deep));
    //dfs1(start,0);
    dfs1(ed,0);

    memset(deep2,0,sizeof(deep2));
    dfs3(start,0);


   for(int i=1;i<=n;++i)
   {
      ll d=min(deep[i],deep2[i]);
      if(d>temp1) temp1=d;

   }

    printf("%lld",ans_end+temp1);
    return 0;

}


