#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=3005;

int n,k,m,dp[maxn][maxn];//�ڵ�i�����j������
int a,c;

//----------------------------
struct Edge
{
	int next;
	int to;
	int w;
};

Edge edge[1000010*2];

int head[maxn];

int cnt = 0;

void add(int u, int v, int w)
{
    edge[++cnt].w = w;
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt;
}


//----------------------------------
int du[maxn];
int ans=1e9;

void dfs(int x,int fa)
{
    dp[x][1]=du[x];
    for(int i=head[x];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==fa) continue;
        dfs(v,x);
        //���鱳��
        for(int j=m;j>0;j--)//��������
        {
            for(int k=1;k<=j;k++)
            {
                dp[x][j]=min(dp[x][j],dp[x][j-k]+dp[v][k]-2);//Ĭ�Ϸ��������ʱ��Ҫ�������ӽڵ�͸��ڵ�
                //���������ʱ���Ѿ������ˣ���ȥ2

            }
        }
    }
    ans=min(ans,dp[x][m]);

}

signed main()
{
    cin>>n>>m;
    memset(dp,0x3f,sizeof(dp));
    for(int i=1;i<=n-1;i++)
    {
        int u,v;
        cin>>u>>v;
        add(u,v,1);
        add(v,u,1);
        du[u]++;
        du[v]++;
    }
    dfs(1,0);
    cout<<ans;
    return 0;
}

