#include<bits/stdc++.h>
using namespace std;
const int maxn=110;
vector<int> tree[maxn];
int n,q;
int a,b,temp;
int value[maxn][maxn],vis[maxn];
int dp[maxn][maxn];//��ʾ���˵�i���ڵ��ʱ����������j����֦
void dfs(int father)
{
    vis[father]=1;//��ֹ�ظ�����
    for(int i=0;i<tree[father].size();i++)
    {
        int son=tree[father][i];
        if(vis[son]==1) continue;
        dfs(son);

        for(int j=q;j>=1;j--)
        {
            for(int k=0;k<j;k++)//���ٸ��ϱ���һ����
            {
                dp[father][j]=max(dp[father][j],value[father][son]+dp[son][k]+dp[father][j-k-1]);
            }
        }
    }

}

int main()
{
    cin>>n>>q;
    for(int i=1;i<n;i++)
    {
        cin>>a>>b>>temp;
        tree[a].push_back(b);
        tree[b].push_back(a);
        value[a][b]=value[b][a]=temp;
        //˫���ߣ������֪�����ĸ��Ǹ��׽ڵ������
    }

    dfs(1);
    cout<<dp[1][q]<<endl;

    return 0;
}

/*
//����Žڵ����⣬���Ż��ǲ�����dp
#include<bits/stdc++.h>
using namespace std;
const int maxn=1550;

int n,k,tmp,fir;
vector<int> a[maxn];
int vis[maxn];

int dp[maxn][2];//��ʾ��ǰ�˵�Ų���

void dfs(int u)
{
    dp[u][0]=0;
    dp[u][1]=1;
    vis[u]=1;
    for(int i=0;i<a[u].size();i++)
    {
        int v=a[u][i];
        if(vis[v]) continue;
        dfs(v);
        dp[u][0]+=dp[v][1];
        dp[u][1]+=min(dp[v][0],dp[v][1]);
    }
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>fir>>k;
        for(int j=1;j<=k;j++)
        {
            cin>>tmp;
            a[fir].push_back(tmp);
            a[tmp].push_back(fir);
        }
    }
    dfs(0);
    cout<<min(dp[0][0],dp[0][1])<<endl;

}*/
