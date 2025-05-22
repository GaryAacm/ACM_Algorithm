#include <iostream>
#include <cstring>
#include<algorithm>
using namespace std;
const int maxn=1e4+10;
const int INF = 1e6;
int n,m,a,b,c,t,w;
int grap[maxn][maxn];
int flag=0;
void floyd()
{
    for(int k=1;k<=n;k++)//枚举分割点
    {
        for(int i=1;i<=n;i++)
        {
            if(grap[i][k]!=INF)//优化
            {
                for(int j=1;j<=n;j++)
                {
                    if(grap[i][j]>grap[i][k]+grap[k][j])//不用min更快
                        grap[i][j]=grap[i][k]+grap[k][j];
                }

            }//一次性找到所有的最短路

           if(grap[i][i]<0) //可以回到
            {
                flag=1;
                return ;
            }
        }

    }
}
int main()
{
    //freopen("D:\\算法进阶\\图论\\最短路\\in.txt","r",stdin);
    scanf("%d",&t);
    while(t--)
    {

        scanf("%d%d%d",&n,&m,&w);
        flag=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
                if(i==j)
                    grap[i][j]=0;
                else
                    grap[i][j]=INF;
        }

        for(int i=1;i<=m;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            if(c<grap[a][b])//细节处理，为了避免出现时间大于1e6赋值
                grap[a][b]=grap[b][a]=c;
        }

        for(int i=0;i<w;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            if(-1*c<grap[a][b])
                grap[a][b]=-1*c;//给边值赋予负数，加入一起讨论
        }

        floyd();
        if (flag) printf("YES\n");
		else printf("NO\n");



    }

    return 0;
}

