#include<bits/stdc++.h>
using namespace std;
#define maxn 5005
#define mod 80112002
int n,m,ans,f[maxn],ind[maxn],outd[maxn];
vector<int> p[maxn];
queue<int> Q;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        outd[x]++;
        ind[y]++;//记录出度和入度
        p[x].push_back(y);//连接起来
    }
    for(int i=1;i<=n;i++)
    {
        if(ind[i]==0)//找出入度为0的起点
        {
            f[i]=1;//初始化
            Q.push(i);
        }
    }
    while(!Q.empty())
    {
        int x=Q.front();
        Q.pop();
        for(int i=0;i<p[x].size();i++)
        {
            int y=p[x][i];//找到连接的边
            f[y]=(f[x]+f[y])%mod;//先取模，避免太大
            ind[y]--;
            if(ind[y]==0)
                Q.push(y);//成为起点入队
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(outd[i]==0)
        {
            //最大食物链一定最后出度为0
            ans=(ans+f[i])%mod;
        }
    }
    cout<<ans;
    return 0;
}

