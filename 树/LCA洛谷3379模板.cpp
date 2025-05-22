#include<bits/stdc++.h>
using namespace std;
struct Edge
{
    int to;
    int next;
}e[500010<<1];
int head[500010],cnt;
void addedge(int x,int y)
{
    cnt++;
    e[cnt].next=head[x];
    e[cnt].to=y;
    head[x]=cnt;
}//���
int depth[500001],fa[500001][22],lg[500001];

void dfs(int now ,int fath)//��¼��Ⱥ͸����������
{
    fa[now][0]=fath;
    depth[now]=depth[fath]+1;
    for(int i=1;i<=lg[depth[now]];++i)
    {
        fa[now][i]=fa[fa[now][i-1]][i-1];//���ת�ƿ���˵���㷨�ĺ���֮һ
	                                //��˼��now��2^i���ȵ���now��2^(i-1)���ȵ�2^(i-1)����
                                    	//2^i = 2^(i-1) + 2^(i-1)
    }
    for(int i=head[now];i;i=e[i].next)
    {
        if(e[i].to!=fath) dfs(e[i].to,now);
    }
}

int LCA(int x,int y)
{
    if(depth[x]<depth[y]) swap(x,y);

    while(depth[x]>depth[y])
        x=fa[x][lg[depth[x]-depth[y]]-1];//������yͬһ��ȵ�x������

    if(x==y)//y��ԭ��x������
        return y;
    for(int k=lg[depth[x]]-1;k>=0;--k)
    {
        if(fa[x][k]!=fa[y][k])
            x=fa[x][k],y=fa[y][k];
    }
    return fa[x][0];
}
int main()
{
    int n,m,s;
    scanf("%d%d%d",&n,&m,&s);
    for(int i=1;i<=n-1;++i)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        addedge(x,y);
        addedge(y,x);
    }
    for(int i=1;i<n;++i)//Ԥ�����log_2(i)+1��ֵ���õ�ʱ��ֱ�ӵ��þͿ�����
    {
        lg[i]=lg[i-1]+(1<<lg[i-1]==i);
    }
    dfs(s,0);
    for(int i=1;i<=m;++i)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%d\n",LCA(x,y));
    }
    return 0;
}

