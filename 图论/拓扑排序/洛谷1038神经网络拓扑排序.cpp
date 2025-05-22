/*#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e3+10;

int n,p,x,y,in[maxn],out[maxn];


int head[maxn],cnt=0;
struct Edge
{
    int nxt,to,wei;
}edge[maxn];

void add_edge(int u,int v,int w)
{
    edge[++cnt].to=v;
    edge[cnt].wei=w;
    edge[cnt].nxt=head[u];
    head[u]=cnt;
}

struct node
{
    int id,state,u;
}a[maxn];

struct Last
{
    int id,last_state;
}last[maxn];

bool cmp(Last x,Last y)
{
    return x.id<y.id;
}

signed main()
{
    cin>>n>>p;
    for(int i=1;i<=n;i++)
    {
        cin>>x>>y;
        a[i].id=i;
        a[i].state=x;
        a[i].u=y;
        if()
    }
    int u,v,w;
    for(int i=1;i<=p;i++)
    {
        cin>>u>>v>>w;
        in[v]++;
        out[u]=1;
        add_edge(u,v,w);
    }

    queue<int> q;
    for(int i=1;i<=n;i++)
    {
        if(in[i]==0) q.push(i);
    }
    int ans=0;//记录数量
    while(!q.empty())
    {
        int now=q.front();
        q.pop();
        for(int i=head[now];i;i=edge[i].nxt)
        {
            int vv=edge[i].to;
            in[vv]--;
            int cost=edge[i].wei;
            a[vv].state+=a[now].state*cost;
            //cout<<"此时的点："<<vv<<" 状态："<<a[v].state<<endl;
            if(in[vv]==0)
            {
                q.push(vv);
            }
        }
    }
    int countt=0;
    bool f=false;
    for(int i=1;i<=n;i++)
    {


            if(a[i].state-a[i].u>0&&!out[i])
            {
                last[++countt].id=a[i].id;
                last[countt].last_state=a[i].state-a[i].u;
                f=true;
            }

    }
    sort(last+1,last+1+countt,cmp);

    for(int i=1;i<=countt;i++)
    {
        cout<<last[i].id<<' '<<last[i].last_state<<'\n';
    }
    if(!f) cout<<"NULL"<<'\n';
    return 0;

}*/


#include<bits/stdc++.h>
#define N 1010
using namespace std;
struct edge{
	int to,val,nxt;
} e[N*N];

struct answer{
	int id,val;
} ans[N];

int h,i,m,n,t,u,v,w,U,c[N],hd[N],out[N],vis[N];//只用c来进行简化
queue <int> q;
int cnt=0,flag=0;
inline bool cmp(answer aa,answer bb)
  {return aa.id<bb.id;}
void build(int u,int v,int w)
 {
 	cnt++;
 	e[cnt].to=v;
 	e[cnt].val=w;
 	e[cnt].nxt=hd[u];
 	hd[u]=cnt;
 }
int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		vis[i]=out[i]=0;
		scanf("%d%d",&c[i],&U);
		//这里不可以直接减，初始层也有可能有阈值，但不能减去.(题目要求)
		if(c[i]>0)
		 {q.push(i);vis[i]=1;}//vis表示是否已入过队
		else c[i]-=U;
	}
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		build(u,v,w);
		out[u]=1;//out表示有无出边，用于最后找输出层,在最后
	}
	while(!q.empty())
	{
		h=q.front();q.pop();
		if(c[h]<=0) continue;
		for(i=hd[h];i;i=e[i].nxt)
		{
			t=e[i].to;
			c[t]+=e[i].val*c[h];
			if(!vis[t]) //神经网络特质，不会重复搞输入层
			{
				q.push(t);
				vis[t]=1;
			}
		}
	}
	for(i=1;i<=n;i++)
	 if(!out[i]&&c[i]>0)
	  {printf("%d %d\n",i,c[i]);flag=1;}
	if(!flag) {puts("NULL");return 0;}
	return 0;
}
