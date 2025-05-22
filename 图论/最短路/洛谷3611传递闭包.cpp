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


                for(int j=1;j<=n;j++)
                {
                    grap[i][j]=max(min(grap[i][k],grap[k][j]),grap[i][j]);//只需要找到i,k是否通行，然后判断i和j
                }

    }


}

int main()
{
    //freopen("D:\\算法进阶\\图论\\最短路\\in.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&grap[i][j]);

        }
    }
    floyd();

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            printf("%d ",grap[i][j]);
        printf("\n");
    }

    return 0;
}
