#include<bits/stdc++.h>
using namespace std;
struct ahah{
	int nxt,to,dis;
}edge[200010];
int n,m;
int head[5010],tot;
void add(int x,int y,int z)
{
	edge[++tot].nxt=head[x],edge[tot].to=y,edge[tot].dis=z,head[x]=tot;
}
int d[5010][2];
bool vis[5010];
queue <int> que;
int read()
{
	int sum=0,fg=1; char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')fg=-1;c=getchar();}
	while(c>='0'&&c<='9'){sum=sum*10+c-'0';c=getchar();}
	return sum*fg;
}
void spfa(int s)
{
	memset(d,0x7f,sizeof(d));//这里分开用两个数组不好，不能更新到位
	que.push(s);vis[s]=1;
	d[s][0]=0;
	while(!que.empty())
	{
		int u=que.front();
		vis[u]=0;que.pop() ;
		for(int i=head[u];i;i=edge[i].nxt)
		{
			int v=edge[i].to;
			if(d[v][0]>d[u][0]+edge[i].dis)
			{
				d[v][1]=d[v][0];
				d[v][0]=d[u][0]+edge[i].dis;
				if(!vis[v])vis[v]=1,que.push(v);
			}
			if(d[v][1]>d[u][0]+edge[i].dis&&d[u][0]+edge[i].dis>d[v][0])//可以更新次短路
			{
				d[v][1]=d[u][0]+edge[i].dis;
				if(!vis[v])vis[v]=1,que.push(v);
			}
			if(d[v][1]>d[u][1]+edge[i].dis)//两次更新次最短
			{
				d[v][1]=d[u][1]+edge[i].dis;
				if(!vis[v])vis[v]=1,que.push(v);
			}

		}
	}
}
int main()
{
	int x,y,z;
	n=read();m=read();
	for(int i=1;i<=m;i++)
	{
		x=read(),y=read(),z=read();
		add(x,y,z);add(y,x,z);
	}
	spfa(1);
	printf("%d",d[n][1]);
}
