#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+10;
const int INF = 1e7+10;
int n,m,a,b,c;
int grap[maxn][maxn];

void floyd()
{
    for(int k=1;k<=n;k++)//ö�ٷָ��
    {
        for(int i=1;i<=n;i++)


                for(int j=1;j<=n;j++)
                {
                    grap[i][j]=max(min(grap[i][k],grap[k][j]),grap[i][j]);//ֻ��Ҫ�ҵ�i,k�Ƿ�ͨ�У�Ȼ���ж�i��j
                }

    }


}

int main()
{
    //freopen("D:\\�㷨����\\ͼ��\\���·\\in.txt","r",stdin);
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
