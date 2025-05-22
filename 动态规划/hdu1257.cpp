#include<bits/stdc++.h>
using namespace std;
int n;
int high[10005];
int dp[1005];//表示第i个数结尾的有最长的子序列
/*int LIS()
{
    memset(dp,0,sizeof(dp));
    int ans=1;
    dp[1]=1;//第一个数为1
    for(int i=2;i<=n;i++)
    {
        int maxx=0;
        for(int j=1;j<i;j++)//遍历前面的数
        {
            if(dp[j]>maxx&&high[j]<high[i])
            {
                maxx=dp[j];//找出最长的更新
            }
            dp[i]=maxx+1;//从小到大更新，不然就加上自己的1
            if(dp[i]>ans) ans=dp[i];
        }
    }
    return ans;

}*/

int LIS()
{
    int d[10005];
    int len=1;
    d[1]=high[1];
    for(int i=2;i<=n;i++)
    {
        if(d[len]<high[i])
        {
            d[++len]=high[i];//更新后面大的节点
        }
        else
        {
            int j=lower_bound(d+1,d+1+len,high[i])-d;//找到d数组中第一个比high当前大的数，替换掉其下一个数字
            d[j]=high[i];
        }
    }
    return len;
}

int main()
{
    while(cin>>n)
    {
        for(int i=1;i<=n;i++)
            cin>>high[i];
        cout<<LIS()<<endl;
    }
    return 0;
}


