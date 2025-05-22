/*�ڸ���LCA��ʱ��˳�����Ȩֵ*/
#include<bits/stdc++.h>
using namespace std;
#define INF 999999999
const int maxn=5e4+10;
struct node
{
    int u,v,w;
}e[250000];


struct Edge2
{
    int to,next,w;

}edge2[100005]; //�����������ͼ

int a,b,cnt,f[maxn],n,m,c,q,head[maxn];
int fa[maxn][21],depth[maxn],wei[maxn][21],lg[500001];
bool vis[maxn];

void addedge(int from, int to, int w)
{ //ǰ���Ǵ�ͼ
    edge2[++cnt].next=head[from];
    edge2[cnt].to=to;
    edge2[cnt].w=w;
    head[from]=cnt;
    return ;
}



bool cmp(node x,node y)
{
        return x.w>y.w;
}
int finded(int x)
{
        if(f[x]==x) return x;
        return f[x]=finded(f[x]);
}

//-----------------------------��ʼ��-----------------------------//

void kruskal()
{
    for(int i=1;i<=m;i++)
    {
        int u=e[i].u;
        int v=e[i].v;
        if(finded(u)!=finded(v))
        {
            f[finded(u)]=f[finded(v)];
            addedge(u,v,e[i].w);
            addedge(v,u,e[i].w);
        }
    }
}

//-------------------------�������������---------------------------------------//


void dfs(int now)//��¼��Ⱥ͸����������
{
    int fath=now;
    vis[now]=true;
    for(int i=head[now];i;i=edge2[i].next)
    {
        int to=edge2[i].to;
        if(vis[edge2[i].to]) continue;
        fa[to][0]=fath;
        depth[to]=depth[fath]+1;
        wei[edge2[i].to][0]=edge2[i].w; //���浽���ڵ��Ȩֵ
        if(edge2[i].to!=fath) dfs(edge2[i].to);
    }
}

int LCA(int x,int y)
{
    if(finded(x)!=finded(y)) return -1;
    int ans=INF;
    if(depth[x]>depth[y]) swap(x,y);

   for(int i=20; i>=0; i--)
        if(depth[fa[y][i]]>=depth[x])
        {
            ans=min(ans, wei[y][i]);  //����������أ���С��Ȩ��
            y=fa[y][i]; //�޸�yλ��
        }

    if(x==y)
        return ans;
   for(int i=20; i>=0; i--)
        if(fa[x][i]!=fa[y][i])
        {
            ans=min(ans, min(wei[x][i], wei[y][i])); //����������أ���С��Ȩ��
            x=fa[x][i];
            y=fa[y][i]; //�޸�x,yλ��
        }
    ans=min(ans, min(wei[x][0], wei[y][0]));
    //���´�ʱx,y����������������أ�fa[x][0], fa[y][0]��Ϊ��������
    return ans;
}

//----------------------------LCA��ѯ---------------------------//

signed main()
{
        scanf("%d%d",&n,&m);
        for(int i=1;i<=m;i++)
        {
           scanf("%d%d%d",&a,&b,&c);
           e[i].u=a;
           e[i].v=b;
           e[i].w=c;
        }
        sort(e+1,e+m+1,cmp);
        for(int i=1;i<=n;i++) f[i]=i;
        kruskal();
        scanf("%d",&q);

        //֮����һ������������ֹͼ����ͨ
        for(int i=1; i<=n; i++)
        if(!vis[i])
        {
            depth[i]=1;
            dfs(i);
            fa[i][0]=i;
            wei[i][0]=INF;//��ʼ������
        }

        //LCA��ʼ��
        for(int i=1; i<=20; i++)
            for(int j=1; j<=n; j++)
            {
                fa[j][i]=fa[fa[j][i-1]][i-1];
                wei[j][i]=min(wei[j][i-1], wei[fa[j][i-1]][i-1]);
            }

        while(q--)
        {
            int ss,ed;
            scanf("%d%d",&ss,&ed);
            printf("%d\n",LCA(ss,ed));

        }
        return 0;
}

