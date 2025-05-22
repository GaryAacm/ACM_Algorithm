#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=3005;

int n,k,m,dp[maxn][maxn],cost[maxn];
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

int dfs(int x)
{
    if(x>n-m)
    {
        //�û�
        dp[x][1]=cost[x];
        return 1;
    }

    int sonsize,sum=0;
    for(int i=head[x];i;i=edge[i].next)
    {
        int v=edge[i].to;
        sonsize=dfs(v);//��ǰ�ڵ���û�����
        sum+=sonsize;//����û�������

        //���鱳��
        for(int j=sum;j>0;j--)//��������
        {
            for(int k=1;k<=sonsize;k++)
            {
                if(j>=k)
                {
                    dp[x][j]=max(dp[x][j],dp[x][j-k]+dp[v][k]-edge[i].w);
                }
            }
        }
    }

    return sum;//�����ۼ��û�����
}

signed main()
{
    cin>>n>>m;
    memset(dp,-0x3f,sizeof(dp));
    for(int i=1;i<=n-m;i++)
    {
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            cin>>a>>c;
            add(i,a,c);
            //add(a,i,c);
        }
    }
    for(int i=n-m+1;i<=n;i++)
    {
        cin>>cost[i];
    }
    for (int i=1;i<=n;i++)
        dp[i][0]=0;

    dfs(1);

    for (int i=m;i>=1;i--)
    if (dp[1][i]>=0)
    {
        cout<<i;
        break;
    }
    return 0;
}
