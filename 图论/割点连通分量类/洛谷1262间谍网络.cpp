#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=10005;
vector<int> G[maxn];
int cnt=0,dfn;
int mindd[maxn];
int low[maxn],top=0;//low���ܹ����ص���Զ���ȣ�num�ǽڵ����˳��
int num[maxn],scnno[maxn],stacked[maxn];//scnno������¼��ǰ�������ĸ���ͨ��
int n,m,u,v,p;
int in[maxn],out[maxn];
map<int,int> mapp;
int cost[maxn];
int last=50000;
void dfs(int u)
{
    num[u]=low[u]=++dfn;//��һ������Ϊ����˳��
    stacked[top++]=u;
    for(int i=0;i<G[u].size();i++)
    {
        int v=G[u][i];
        if(!num[v])
        {
            dfs(v);
            low[u]=min(low[u],low[v]);//���ϸ��»��˱�
        }
        else if(!scnno[v])//û�мӽ���ͨ��
            low[u]=min(low[u],num[v]);

    }
    if(low[u]==num[u])//��ǰ��ͨ��ĵ������
    {
        cnt++;
        int mink=1e9;
        while(1)
            {
                int v=stacked[--top];//��ջ����ʾͬһ������Ԫ��
                scnno[v]=cnt;
                //cout<<cnt<<endl;
                mink=min(mink,v);
                if(u==v) break;//�ҵ�ջ�׵��Ǹ���
            }
            mindd[cnt]=mink;//�ҵ�����������С��id
    }
}

void Tarjan(int n)
{
    cnt=0;
    for(int i=0;i<=n;i++)
        cost[i]=1e9;
    top=dfn=0;
    memset(num,0,sizeof(num));
    memset(scnno,0,sizeof(scnno));
    memset(low,0,sizeof(low));
    for(int i=1;i<=n;i++)
    {
        if(!num[i])
            dfs(i);
    }

}

void solve(int u)//����������ͼ����Ⱥͳ���
{
    for(int i=0;i<G[u].size();i++)
    {
        int v=G[u][i];
        if(scnno[u]!=scnno[v])
        {
            if(mapp[u]||in[scnno[u]]) cost[scnno[u]]=min(mapp[u],cost[scnno[u]]),in[scnno[v]]=1;
        }

    }

}

signed main()
{
    //freopen("C:\\Users\\asus\\Desktop\\P1262_2.in","r",stdin);
    int minn=1e9;
    cin>>n>>p;
    for(int i=1;i<=p;i++)
    {
        cin>>u>>v;
        mapp[u]=v;
        minn=min(minn,v);
    }
    for(int i=0;i<=n;i++)
    {
        G[i].clear();
    }
    cin>>m;
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
    }
    Tarjan(n);
    for(int i=1;i<=n;i++) solve(i);
    int ans=0,id=1e9;
    bool f=true;
    for(int i=1;i<=cnt;i++)
    {
        if(!in[i])//���Ϊ0�ĵ㣬һ��Ҫ���������һ�����
        {
            if(cost[i]==1e9)//���Ϊ0�ĵ����˲�������
            {
                f=false;
                id=min(id,mindd[i]);
                //cout<<i<<' '<<id<<' '<<mindd[i]<<endl;
                //break;
            }
            if(f) ans+=cost[i];
        }
    }
    if(cnt==1)
    {
        cout<<"YES"<<endl;
        cout<<minn<<endl;
    }
    else
    {
        if(f)
        {
            cout<<"YES"<<endl;
            cout<<ans;
        }
        else
        {
            cout<<"NO"<<endl;
            cout<<id<<endl;
        }
    }
    return 0;
}

/*#include<iostream>
#include<cstdio>
#include<vector>
#include<stack>
#include<algorithm>
#define INF (int)0x3f3f3f3f
#define maxn 10010
using namespace std;
int n,p,num,cnt;   // num��tarjan��ʱ���   cnt������ʱά��ǿ��ͨ�����ĸ���
int w[maxn],dfn[maxn],low[maxn];
int mi[maxn],k[maxn],minid[maxn];    //   ����� pwÿ��ǿ��ͨ��������С����  k[i]��ʾi�������ĸ�ǿ��ͨ����
bool vis[maxn],flag[maxn][maxn],ru[maxn];    //  vis�����ʾi�Ƿ���������  flag��ʾi j����ǿ��ͨ������û������
vector<int> v[maxn];
stack<int> s;
void tarjan(int x)    //  ��׼��tarjan
{
	low[x]=dfn[x]=++num;
	s.push(x);
	vis[x]=true;
	for(int i=0;i<v[x].size();i++)
	{
		int ed=v[x][i];
		if(!dfn[ed])
		{
			tarjan(ed);
			low[x]=min(low[x],low[ed]);
		}
		else if(vis[ed]) low[x]=min(low[x],dfn[ed]);
	}
	if(dfn[x]==low[x])    //  x��һ���ؼ���
	{
		int minw=INF,lk=INF,t;
		cnt++;
		while(1)
		{
			t=s.top();
			s.pop();
			vis[t]=false;
			minw=min(minw,w[t]);     //   ȡ���ǿ��ͨ��������С����
			lk=min(lk,t);
			k[t]=cnt;
			if(t==x) break;
		}
		minid[cnt]=lk;
		mi[cnt]=minw;
	}
}
int main()
{
	scanf("%d%d",&n,&p);           //  n�����  ��p�����Ը�ⱻ����
	for(int i=1;i<=n;i++) w[i]=INF; // �ȳ�ʼ�� ���i�ż������ΪINF˵�������ܱ�����
	int a,b;
	for(int i=1;i<=p;i++)
	{
		scanf("%d%d",&a,&b);       //  a�ż��Ը�ⱻ����
		w[a]=b;     		   //   w�������ÿ�����Ը�ⱻ����Ľ��
	}
	int r;
	scanf("%d",&r);
	for(int i=1;i<=r;i++)
	{
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i]) tarjan(i);    	 	//   tarjan����
	for(int i=1;i<=n;i++)  // ע�⣡����ʵ����û�����㽨��ͼ�Ĳ�������Ϊ����Ҫ
	{
		for(int j=0;j<v[i].size();j++)
		{
			int ed=v[i][j];
			if(k[i]==k[ed]||flag[k[i]][k[ed]]) continue; // ͬһ��ǿ��ͨ�����ĵ�ֱ������ ��������ǿ��ͨ�����Ѿ��жϹ���
			flag[k[i]][k[ed]]=true;
			if(ru[k[i]]||mi[k[i]]!=INF) ru[k[ed]]=true;    //   �ص㣡���i������ǿ��ͨ�������ܱ���¸ �򣡲��ܱ������㵽�� ������ָ��ĵ㲻��¼�����
		}
	}
	int id=INF,all=0;    //   ������������� �ҵ�����С���id
	bool f=false;
	for(int i=1;i<=cnt;i++)
	{
		if(ru[i]) continue;   //  ����ȵĵ�����
		if(mi[i]==INF)    //  ���ǿ��ͨ���������� ˵������ͼ���޽���
		{
			f=true;
			id=min(id,minid[i]);   // �ҵ���С���
		}
		if(!f) all+=mi[i];
	}
	if(f) printf("NO\n%d",id);
	else printf("YES\n%d",all);
	return 0;
}*/
