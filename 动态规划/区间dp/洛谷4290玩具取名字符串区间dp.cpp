/*区间dp把所有的情况都算了一遍，思路就是区间dp枚举区间，找遍全部能够转化的情况*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=205;
int dp[maxn][maxn][5],able[5][5][5];//表示1号可以由2，3转化而来
int q[5];
char c[2],s[maxn];
int change(char x)
{
    if(x=='W') return 1;
    else if(x=='I') return 2;
    else if(x=='N') return 3;
    else return 4;
}

int main()
{
    for(int i=1;i<=4;i++)
    {
        cin>>q[i];
    }
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=q[i];j++)
        {
            cin>>c[0]>>c[1];
            able[i][change(c[0])][change(c[1])]=1;//表示可以转化
        }
    }
    cin>>s+1;
    int len=strlen(s+1);
    for(int i=1;i<=len;i++) dp[i][i][change(s[i])]=true;//从i到i可以由他自己转化
    //开始区间dp
    for(int mid=1;mid<=len;mid++)
    {
        for(int l=1;l+mid<=len;l++)
        {
            int r=l+mid;//右端点
            for(int k=l;k<r;k++)//断点
            {
                //关键
                for(int a1=1;a1<=4;a1++)//列举l到r可能转化成的字母
                    {
                        for(int a2=1;a2<=4;a2++)//列举l到k
                        {
                            for(int a3=1;a3<=4;a3++)//列举k + 1到r
                            {
                                if(able[a1][a2][a3]&&dp[l][k][a2]&&dp[k+1][r][a3])//l到k可以由a2转化来
                                    dp[l][r][a1]=1;
                            }
                        }
                    }
            }
        }
    }
    bool flag=false;
    if(dp[1][len][1]) {flag=true;cout<<'W';}
    if(dp[1][len][2]) {flag=true;cout<<'I';}
    if(dp[1][len][3]) {flag=true;cout<<'N';}
    if(dp[1][len][4]) {flag=true;cout<<'G';}
    if(!flag) cout<<"The name is wrong!";

    return 0;
}
