#include<bits/stdc++.h>
using namespace std;
const int maxn=10010;
struct node
{
    int x,y,tim;
}a[maxn];
int dp[maxn],n,m;//dp表示到第i只小鼠的时候抓到了几只

int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
        cin>>a[i].tim>>a[i].x>>a[i].y;
    for(int i=1;i<=m;i++)
        dp[i]=1;//初始化为1
    int maxnn=-1;
    //如果初始化为0，但是枚举包括自己也不行，因为可能不经过自己
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<i;j++)//枚举前面的老鼠,不能枚举自己，否则会重复
        {
            if(abs(a[i].x-a[j].x)+abs(a[i].y-a[j].y)<=abs(a[i].tim-a[j].tim))
            {
                //可以达到
                dp[i]=max(dp[i],dp[j]+1);

            }

        }
        maxnn=max(maxnn,dp[i]);
    }
    cout<<maxnn<<endl;
    return 0;
}

