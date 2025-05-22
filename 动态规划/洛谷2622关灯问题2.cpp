#include<bits/stdc++.h>
using namespace std;
const int maxn=110;
int n,m,a[maxn][maxn*10];
bool vis[1000010];

struct Node
{
    int s,step;//存储状态和步数
};

queue<Node> q;

int bfs()
{
    int now;
    q.push((Node){(1<<n)-1,0});
    vis[(1<<n)-1]=1;
    while(!q.empty())
    {
        Node u=q.front();
        q.pop();
        if(u.s==0) return u.step;

        for(int i=1;i<=m;i++)
        {
            now=u.s;
            for(int j=1;j<=n;j++)
            {
                if(a[i][j]==1&&(now&(1<<j-1))) now^=(1<<j-1);//与第j位上的作处理
                else if(a[i][j]==-1&&!(now&(1<<j-1))) now|=(1<<j-1);
            }
            if(!vis[now])
            {

                q.push((Node){now,u.step+1});
                vis[now]=1;
            }
        }
    }
    return -1;
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
        }
    }
    cout<<bfs()<<endl;
    return 0;
}
