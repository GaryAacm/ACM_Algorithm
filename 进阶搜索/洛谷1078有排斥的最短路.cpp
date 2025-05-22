#include<bits/stdc++.h>
using namespace std;

int n,k,m,s,t;
int dp[120][120],a[120],g[120][120];
int u,v,d;
int main()
{
     cin>>n>>k>>m>>s>>t;
    for(register int i=1;i<=n;i++)
        for(register int j=1;j<=n;j++)
        	dp[i][j]=21743822;

    for(register int i=1;i<=n;i++)
    {
        cin>>a[i];//文化
    }
     for(register int i=1;i<=k;i++){
        for(register int j=1;j<=k;j++)
        {
            cin>>g[i][j];//表示关系
        }
    }
    for(register int i=1;i<=m;i++)
    {
        cin>>u>>v>>d;
        if(!g[a[u]][a[v]]&&a[u]!=a[v]) dp[u][v]=min(dp[u][v],d);
        if(!g[a[v]][a[u]]&&a[u]!=a[v]) dp[v][u]=min(dp[v][u],d);

    }
    if(a[s]==a[t]) {cout<<-1<<endl;return 0;}

    for(register int i=1;i<=n;i++)
    {
        for(register int j=1;j<=n;j++)
        {
            if(i!=j)
            {
                for(register int p=1;p<=n;p++)
                {
                    if(i!=p&&j!=p)
                    {
                        if(dp[i][j]>dp[i][p]+dp[p][j])
                        {
                            dp[i][j]=dp[i][p]+dp[p][j];
                        }
                    }
                }
            }

        }
    }
    if(dp[s][t]==21743822) cout<<-1<<endl;
    else cout<<dp[s][t]<<endl;
}
