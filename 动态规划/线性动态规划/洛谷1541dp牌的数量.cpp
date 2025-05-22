/*思想就是因为牌数足够到达，所以枚举每次使用的牌数并且做出dp*/
#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn=401;

int dp[45][45][45][45];//表示使用的每种牌的数目
int n,m,a,b,c,d,pos;
int val[maxn],g[5];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>val[i];
    }
    for(int i=1;i<=m;i++)
    {
        int temp;
        cin>>temp;
        g[temp]++;
    }//记录有多少张牌
    dp[0][0][0][0]=val[1];
    for(a=0;a<=g[1];a++)
        for(b=0;b<=g[2];b++)
    {
        for(c=0;c<=g[3];c++)
        {
            for(d=0;d<=g[4];d++)
            {
                pos=1+a+b*2+c*3+d*4;//表示走到的位置
                if(a!=0) dp[a][b][c][d]=max(dp[a][b][c][d],dp[a-1][b][c][d]+val[pos]);
                if(b!=0) dp[a][b][c][d]=max(dp[a][b][c][d],dp[a][b-1][c][d]+val[pos]);
                if(c!=0) dp[a][b][c][d]=max(dp[a][b][c][d],dp[a][b][c-1][d]+val[pos]);
                if(d!=0) dp[a][b][c][d]=max(dp[a][b][c][d],dp[a][b][c][d-1]+val[pos]);
            }
        }
    }
    cout<<dp[g[1]][g[2]][g[3]][g[4]];

    return 0;


}
