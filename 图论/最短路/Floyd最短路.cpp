#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+10;
const int INF = 1e7+10;
int n,m,a,b,c;
int grap[maxn][maxn];

void floyd()
{
    for(int k=1;k<=n;k++)//枚举分割点
    {
        for(int i=1;i<=n;i++)
            if(grap[i][k]!=INF)//优化
            {
                for(int j=1;j<=n;j++)
                {
                    if(grap[i][j]>grap[i][k]+grap[k][j])//不用min更快
                        grap[i][j]=grap[i][k]+grap[k][j];
                }
            }
    }

    printf("%d\n",grap[1][n]);
}

int main()
{
    //freopen("D:\\算法进阶\\图论\\最短路\\in.txt","r",stdin);
    while(scanf("%d%d",&n,&m)!=EOF)
    {

        if(m==0&&n==0) break;
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
                grap[i][j]=INF;
        }

        for(int i=1;i<=m;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            grap[a][b]=grap[b][a]=c;
        }
        floyd();
    }

    return 0;
}
