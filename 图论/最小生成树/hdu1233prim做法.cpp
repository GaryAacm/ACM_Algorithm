#include<bits/stdc++.h>
using namespace std;
const int maxn=200005;
#define inf 123456789
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

 int prim()
 {

     for(int i=1;i<=n;++i)
     {
         dis[i]=inf;
     }//��ʼ��
     for(int i=head[1];i;i=edge[i].next)//�ҽڵ㣬�ӵ�һ���㿪ʼ��ʼ��
     {
         dis[edge[i].to]=min(dis[edge[i].to],edge[i].wei);
     }
     while(++tot<n)//��ʼ����
        {
            int minn=inf;
            int t=now;
            vis[now]=1;
            for(int i=1;i<=n;i++)//ö�����еĽڵ�Ϊ�˸��·���
            {
                if(!vis[i]&&minn>dis[i])
                {
                    minn=dis[i];
                    now=i;//������С�Ľڵ�
                }
            }
            if(t==now) return -1;
            ans+=minn;
            for(int i=head[now];i;i=edge[i].next)
            {
                int t=edge[i].to;
                if(!vis[t]&&dis[t]>edge[i].wei)
                {
                    dis[t]=edge[i].wei;//���½ڵ�
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
         addedge(a,b,c),addedge(b,a,c);//���������
     }
     if(prim()==-1) cout<<"orz"<<endl;
     else cout<<prim()<<endl;
     return 0;
 }
