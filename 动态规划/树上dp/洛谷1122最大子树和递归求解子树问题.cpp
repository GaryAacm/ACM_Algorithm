#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn=2e5+10;

int n,cost[maxn],u,v;
vector<int> a[maxn];
int dp[maxn];

void dfs(int u,int fa)
{
    dp[u]=cost[u];//��ǰ�����ڸ���
    for(int i=0;i<a[u].size();i++)
    {
        int v=a[u][i];
        if(v!=fa)
        {
            dfs(v,u);
            if(dp[v]>0)
            {
                dp[u]+=dp[v];//�ҵ��������������
            }
        }
    }
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>cost[i];
    }
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    dfs(1,0);
    int ans=-1e9;
    for(int i=1;i<=n;i++)
    {
        ans=max(dp[i],ans);
    }

    cout<<ans<<endl;
    return 0;
}
