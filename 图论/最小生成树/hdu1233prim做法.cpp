#include<bits/stdc++.h>
using namespace std;
const int maxn=200005;
#define inf 123456789
int head[maxn],cnt,ans,tot,now=1,n,m,a,b,c,vis[maxn],dis[maxn];
struct edge
{
    int to,wei,next;
}edge[maxn<<1];//无向图开两倍数组

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}

 void addedge(int x,int y,int z)//链式向前星存图
 {
     edge[++cnt].next=head[x];
     edge[cnt].to=y;
     edge[cnt].wei=z;
     head[x]=cnt;
 }

 int prim()
 {

     for(int i=1;i<=n;++i)
     {
         dis[i]=inf;
     }//初始化
     for(int i=head[1];i;i=edge[i].next)//找节点，从第一个点开始初始化
     {
         dis[edge[i].to]=min(dis[edge[i].to],edge[i].wei);
     }
     while(++tot<n)//开始造树
        {
            int minn=inf;
            int t=now;
            vis[now]=1;
            for(int i=1;i<=n;i++)//枚举所有的节点为了更新方便
            {
                if(!vis[i]&&minn>dis[i])
                {
                    minn=dis[i];
                    now=i;//更新最小的节点
                }
            }
            if(t==now) return -1;
            ans+=minn;
            for(int i=head[now];i;i=edge[i].next)
            {
                int t=edge[i].to;
                if(!vis[t]&&dis[t]>edge[i].wei)
                {
                    dis[t]=edge[i].wei;//更新节点
                }
            }
        }
        return ans;
 }

 int main()
 {
     n=read(),m=read();
     for(int i=1;i<=m;++i)
     {
         a=read(),b=read(),c=read();
         addedge(a,b,c),addedge(b,a,c);//建立无向边
     }
     if(prim()==-1) cout<<"orz"<<endl;
     else cout<<prim()<<endl;
     return 0;
 }
