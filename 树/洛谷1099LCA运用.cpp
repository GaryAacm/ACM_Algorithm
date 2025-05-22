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
}//���
int depth[500001],fa[500001][22],lg[500001];
int a,b,c,d;
int u,v,n,q,t;
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

    //while(depth[x]>depth[y])
        //x=fa[x][lg[depth[x]-depth[y]]-1];//������yͬһ��ȵ�x������

    for(int i=t;i>=0;i--) if(depth[fa[y][i]]>=depth[x]) y=fa[y][i];

    if(x==y)//y��ԭ��x������
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
    //freopen("D:\\�㷨����\\��\\in.txt","r",stdin);
    scanf("%d%d",&n,&q);
    t=(int)(log(n)/log(2))+1;
    for(int i=1;i<n;++i)
    {
        scanf("%d%d",&u,&v);
        add(u,v);
        add(u,v);
    }
     for(int i=1;i<n;++i)//Ԥ�����log_2(i)+1��ֵ���õ�ʱ��ֱ�ӵ��þͿ�����
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
