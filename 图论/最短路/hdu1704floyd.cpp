#include<bits/stdc++.h>
using namespace std;
const int maxn=505;
//const int INF = 0x3f3f3f3f;
int n,m,a,b,c,t;
int grap[maxn][maxn];
int flag=0;
void floyd()
{
    for(int k=1;k<=n;k++)//枚举分割点
    {
        for(int i=1;i<=n;i++)
        {
            if(grap[i][k]!=0x3f3f3f3f)//优化
            {
                for(int j=1;j<=n;j++)
                {
                    if(grap[i][j]>grap[i][k]+grap[k][j])//不用min更快
                        grap[i][j]=grap[i][k]+grap[k][j];
                        //grap[i][j]=1;
                }

            }//一次性找到所有的最短路


        }

    }
}

int main()
{
    //freopen("D:\\算法进阶\\图论\\最短路\\in.txt","r",stdin);
   scanf("%d",&t);
   while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
                if(i==j)
                    grap[i][j]=0;
                else
                    grap[i][j]=0x3f3f3f3f;
        }
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d",&a,&b);
            grap[a][b]=0;//分出胜负,只看一边

        }
        floyd();
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)//避免判断自己
            {
                if(grap[i][j]==0x3f3f3f3f&&grap[j][i]==0x3f3f3f3f) ans++;
            }
        }
        printf("%d\n",ans);

    }

    return 0;
}
