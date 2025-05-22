#include<bits/stdc++.h>
using namespace std;
struct Edge
{
    int to;
    int next;
}e[500010<<1];
int head[500010],cnt;
void add(int x,int y)
{
    cnt++;
    e[cnt].next=head[x];
    e[cnt].to=y;
    head[x]=cnt;
}//存边
int depth[500001],fa[500001][22],lg[500001];
int a,b,c,d;
int u,v,n,q,t;
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

    //while(depth[x]>depth[y])
        //x=fa[x][lg[depth[x]-depth[y]]-1];//跳到和y同一深度的x的祖先

    for(int i=t;i>=0;i--) if(depth[fa[y][i]]>=depth[x]) y=fa[y][i];

    if(x==y)//y是原来x的祖先
        return y;
    for(int k=t;k>=0;--k)
    {
        if(fa[x][k]!=fa[y][k])
            x=fa[x][k],y=fa[y][k];
    }
    return fa[x][0];
}


int main()
{
    //freopen("D:\\算法进阶\\树\\in.txt","r",stdin);
    scanf("%d%d",&n,&q);
    t=(int)(log(n)/log(2))+1;
    for(int i=1;i<n;++i)
    {
        scanf("%d%d",&u,&v);
        add(u,v);
        add(u,v);
    }
     for(int i=1;i<n;++i)//预先算出log_2(i)+1的值，用的时候直接调用就可以了
    {
        lg[i]=lg[i-1]+(1<<lg[i-1]+1==i);
    }
    depth[1]=1;
    dfs(1,0);
    while(q--)
    {
        scanf("%d%d%d%d",&a,&b,&c,&d);
        int k1=LCA(a,b);
        int k2=LCA(c,d);
        /*if((depth[k1]>=depth[k2]&&(LCA(k1,c)==k1||LCA(k1,d)==k1))||(depth[k2]>=depth[k1]&&(LCA(k2,a)==k2||LCA(k2,b)==k2)))
           printf("Y\n");
        else
            printf("N\n");*/
        if(depth[k1]<depth[k2])
        {
            swap(k1,k2);
            swap(a,c);
            swap(b,d);
        }

        if(LCA(c,k1)==k1||LCA(d,k1)==k1)    cout<<"Y"<<endl;
        else    cout<<"N"<<endl;

    }

    return 0;

}
