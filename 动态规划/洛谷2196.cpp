#include<bits/stdc++.h>
using namespace std;
const int maxn=30;
int n,num[maxn],ans;
int f[maxn][maxn];
int p[maxn],op[maxn],cnt,tot;//p记录最优路径，op记录当前的路径
void dfs(int u,int sum)
{
    for(int i=u+1;i<=n;i++)
    {
        if(f[u][i])//检查当前点后面的链接点的路径
        {
            op[++cnt]=i;//记录路径
            dfs(i,sum+num[i]);
            cnt--;
        }
    }
    if(sum>ans)
    {
        ans=sum;
        for(int i=1;i<=cnt;i++)
        {
            p[i]=op[i];

        }
        tot=cnt;
    }
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>num[i];

    for(int i=1;i<n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            cin>>f[i][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        op[++cnt]=i;//j记录开始的路径
        dfs(i,num[i]);
        cnt--;
    }
    for(int i=1;i<=tot;i++)
        cout<<p[i]<<' ';
    cout<<endl;
    cout<<ans<<endl;
    return 0;

}
