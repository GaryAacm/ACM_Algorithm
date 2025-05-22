#include<cstdio>
#include<algorithm>
#define M 500005
using namespace std;
int n,m,x,y,z,k,id,top,ans=2e9+1;
int dis[M],fa[M],head[M];
bool mark[M];
struct edge{
    int to,w,nxt;
}E[M<<1];
void add(int u,int v,int w){
    E[++id]=((edge){v,w,head[u]});
    head[u]=id;//��ͼ
}

void dfs(int f,int x){
    fa[x]=f;//��¼���׽ڵ�
    if(dis[x]>dis[k])k=x;
    for(int i=head[x];i;i=E[i].nxt){
        int y=E[i].to;
        if(y==f||mark[y])continue;
        dis[y]=dis[x]+E[i].w;
        dfs(x,y);
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<n;i++){
        scanf("%d%d%d",&x,&y,&z);
        add(x,y,z),add(y,x,z);
    }
    dis[1]=1,dfs(0,1);
    dis[k]=0,dfs(0,k);
    //k��ʾ��Զ�Ķ˵�

    top=k;//��ֱ��
    for(int i=top,j=top,l=1,r=0;i;i=fa[i]){
        while(dis[j]-dis[i]>m)j=fa[j];
        //���г�ȡ��ѡ·����
        x=max(dis[top]-dis[j],dis[i]);
        //·�����˵㵽ֱ���˵����С����.
        ans=min(ans,x);
    }
    for(int i=top;i;i=fa[i])mark[i]=1;
    //���ֱ�������¼���ÿ����Ĺ��ס�
    for(int i=top;i;i=fa[i]){
        k=i,dis[k]=0;
        dfs(fa[i],i);
    }
    for(int i=1;i<=n;i++)
        ans=max(ans,dis[i]);

    printf("%d\n",ans);
    return 0;
}


