#include<bits/stdc++.h>
using namespace std;
const int maxn=60;
int n,m,dis[maxn][maxn];
bool G[60][60][65];//表示i到j能否有2的k次长的路径
int x,y;
void floyd()//求最短路
{
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
}

int main()
{
    cin>>n>>m;
    memset(dis,0x3f,sizeof(dis));
    memset(G,false,sizeof(G));
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y;
        G[x][y][0]=true;
        dis[x][y]=1;
    }
    for(int k=1;k<=64;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int t=1;t<=n;t++)
            {
                for(int j=1;j<=n;j++)//注意枚举顺序
                {
                    if(G[i][t][k-1]&&G[t][j][k-1])
                    {
                        G[i][j][k]=true;
                        //标记从i到j存在一条长度为2^k的路径
                        dis[i][j]=1;
                        //i到j距离可以一秒到达
                    }
                }
            }
        }
    }
    floyd();
    cout<<dis[1][n]<<endl;

    return 0;
}
