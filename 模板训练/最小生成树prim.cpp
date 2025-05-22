#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=200005;
#define inf 123456789

//==================================================//

int head[maxn],cnt,ans,tot,now=1,n,m,a,b,c,vis[maxn],dis[maxn];
struct edge
{
    int to,wei,next;
}edge[maxn<<1];//����ͼ����������

inline int read()
{
    int x=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
    return x*f;
}

void addedge(int x,int y,int z)//��ʽ��ǰ�Ǵ�ͼ
{
     edge[++cnt].next=head[x];
     edge[cnt].to=y;
     edge[cnt].wei=z;
     head[x]=cnt;
}
//===================��ʽ��ǰ======================//

int prim()
{
    for(int i=0;i<=n;i++)
    {
        dis[i]=inf;
    }
    for(int i=head[1];i;i=edge[i].next)
    {
        dis[edge[i].to]=min(dis[edge[i].to],edge[i].wei);
    }
    while(++tot<n)
    {
        int minn=inf;//�ҵ���ǰ�����ӵ�����̱�
        int t=now;
        vis[now]=1;
        for(int i=1;i<=n;i++)//�����еĵ�
        {
            if(!vis[i]&&dis[i]<minn)
            {
                now=i;
                minn=dis[i];
            }
        }
        ans+=minn;
        //vis[now]=1;
        if(t==now) return -1;
        for(int i=head[now];i;i=edge[i].next)
        {
            int v=edge[i].to;
            if(!vis[v]&&dis[v]>edge[i].wei)
            {
                dis[v]=edge[i].wei;
            }
        }
    }
    return ans;
}


signed main()
{
     n=read(),m=read();
     for(int i=1;i<=m;++i)
     {
         a=read(),b=read(),c=read();
         addedge(a,b,c),addedge(b,a,c);//���������
     }
     now=1;
     if(prim()==-1) cout<<"orz"<<endl;
     else cout<<prim()<<endl;
     return 0;
}
