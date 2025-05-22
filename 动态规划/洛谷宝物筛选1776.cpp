#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;

int n,w;
int dp[maxn],aval[maxn],bwei[maxn],num[maxn];
int val[maxn*10],cost[maxn*10];
int tp;
void pre()
{
    for(int i=1;i<=n;i++)
    {
        int t=1;
        while(num[i])
        {
            cost[++tp]=t*bwei[i];

            val[tp]=t*aval[i];

            num[i]-=t;
            t*=2;

            if(num[i]<t)
            {
                cost[++tp]=num[i]*bwei[i];

                val[tp]=num[i]*aval[i];
                break;
            }


        }
    }
}

int main()
{
    scanf("%d%d",&n,&w);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d%d",&aval[i],&bwei[i],&num[i]);

    }

    pre();//二进制处理

    for(int i=1;i<=tp;i++)
    {
        for(int j=w;j>=cost[i];j--)
        {
            dp[j]=max(dp[j],dp[j-cost[i]]+val[i]);
        }
    }

    cout<<dp[w]<<endl;

    return 0;
}
