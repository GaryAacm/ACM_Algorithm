#include<bits/stdc++.h>
using namespace std;
#define N 1010
int n,m,dp[N][N],v[N],val[N];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {

        scanf("%d%d",&v[i],&val[i]);
    }
    //��������
    //��ʼdp
    for(int i=1;i<=n;i++)
    {

        for(int j=1;j<=m;j++)
        {
            dp[i][j]=dp[i-1][j];//�̳���һ������
            if(j>=v[i]) dp[i][j]=max(dp[i-1][j],dp[i][j-v[i]]+val[i]);
        }

    }
    /*for(int i=0;i<=n;i++)
    {

        for(int j=0;j<=m;j++)
        {

            printf("%d ",dp[i][j]);
        }
        printf("\n");
    }*/
    printf("%d",dp[n][m]);
    return 0;
}
