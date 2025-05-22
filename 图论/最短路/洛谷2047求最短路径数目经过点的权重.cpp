#include<bits/stdc++.h>
typedef long long LL;
using namespace std;
int read()
{
    int x=0;char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
    return x;
}

int n,m;

LL dis[110][110],edge[110][110];//��ʾ���·������
double ans[110];
LL INF;
int main()
{
    n=read();m=read();
    memset(dis,0x7f,sizeof(dis));
    memset(edge,0,sizeof(dis));
    INF=dis[1][1];
    for(int i=1;i<=m;i++)
    {
        LL x,y,z;
        x=read();y=read();z=read();
        dis[x][y]=dis[y][x]=z;
        edge[x][y]=edge[y][x]=1;
    }

    for(int k=1;k<=n;k++)
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    {
        if(dis[i][k]==INF&&dis[k][j]==INF)continue;

        if(dis[i][j]>dis[i][k]+dis[k][j])
        {
            dis[i][j]=dis[i][k]+dis[k][j];

            edge[i][j]=edge[i][k]*edge[k][j];//�������·������

        }
        else if(dis[i][j]==dis[i][k]+dis[k][j])
            {edge[i][j]+=edge[i][k]*edge[k][j];}
    }

    for(int i=1;i<=n;i++)//ö�پ������м��
    {
        for(int j=1;j<=n;j++)
        for(int k=1;k<=n;k++)//ö�������յ�
        {
            if(i==j||j==k||i==k)
                continue;

            if(dis[j][i]+dis[i][k]==dis[j][k])
            //��ʾiΪ�м�������·���ؼ������ö�پ���i�����·��Ȼ���ж��Ƿ񾭹�iΪ���·
            {
                ans[i]+=(1.0*edge[j][i]*edge[i][k])/edge[j][k];
            }
        }
    }
    for(int i=1;i<=n;i++)
        printf("%0.3f\n",ans[i]);
    return 0;

}
