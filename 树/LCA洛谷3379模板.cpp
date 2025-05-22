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
}//存边
int depth[500001],fa[500001][22],lg[500001];

void dfs(int now ,int fath)//记录深度和各个点的祖先
{
    fa[now][0]=fath;
    depth[now]=depth[fath]+1;
    for(int i=1;i<=lg[depth[now]];++i)
    {
        fa[now][i]=fa[fa[now][i-1]][i-1];//这个转移可以说是算法的核心之一
	                                //意思是now的2^i祖先等于now的2^(i-1)祖先的2^(i-1)祖先
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
        x=fa[x][lg[depth[x]-depth[y]]-1];//跳到和y同一深度的x的祖先

    if(x==y)//y是原来x的祖先
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
    for(int i=1;i<n;++i)//预先算出log_2(i)+1的值，用的时候直接调用就可以了
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

