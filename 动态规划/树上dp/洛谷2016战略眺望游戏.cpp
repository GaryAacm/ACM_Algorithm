#include<bits/stdc++.h>
using namespace std;
const int maxn=1550;

int n,k,tmp,fir;
vector<int> a[maxn];
int vis[maxn];

int dp[maxn][2];//表示当前端点放不放

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

}
