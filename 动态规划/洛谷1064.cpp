#include<bits/stdc++.h>
using namespace std;
const int maxn=33333;

int m,n,mainwg[maxn],mainval[maxn],fuwg[maxn][3],fuval[maxn][3];
int dp[maxn],v,q,p;

int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>v>>p>>q;//合并主件和附件
        if(!q)//主件
        {
            mainwg[i]=v;//主件花费
            mainval[i]=v*p;//主件价值
        }
        else
        {
            //处理附件
            fuwg[q][0]++;//主件的附件数目
            fuwg[q][fuwg[q][0]]=v;//第几个附件的价值花费
            fuval[q][fuwg[q][0]]=v*p;//对应主件下附件的价值
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=n;j>=mainwg[i];j--)//滚动数组优化
        {
            //取这个主件
            dp[j]=max(dp[j],dp[j-mainwg[i]]+mainval[i]);

            //取主件和附件1
            if(j>=mainwg[i]+fuwg[i][1]) dp[j]=max(dp[j],dp[j-mainwg[i]-fuwg[i][1]]+mainval[i]+fuval[i][1]);

            //主件和附件2
            if(j>=mainwg[i]+fuwg[i][2]) dp[j]=max(dp[j],dp[j-mainwg[i]-fuwg[i][2]]+mainval[i]+fuval[i][2]);

            //主件和两个附件
            if(j>=mainwg[i]+fuwg[i][1]+fuwg[i][2]) dp[j]=max(dp[j],dp[j-mainwg[i]-fuwg[i][1]-fuwg[i][2]]+mainval[i]+fuval[i][1]+fuval[i][2]);

        }
    }
    cout<<dp[n]<<endl;
    return 0;
}
