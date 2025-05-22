#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn=105;
char a[maxn][maxn],c,k[9]=" yizhong";
bool s[maxn][maxn];//判断是否要原样输出
int n,d,wei[1005][2];//记录y出现的位置
int x[9]={0,1,0,1,-1,0,-1,1,-1};//八个方位
int y[9]={0,0,1,1,0,-1,-1,-1,1};

bool solve(int n,int m,int x,int y,int nxt)//n,m是当前的方位,x,y是搜索的方向
{
    if(nxt>=8)//比对完成
    {
        s[n][m]=true;
        return true;

    }
    if(a[n+x][m+y]==k[nxt])
    {
        if(solve(n+x,m+y,x,y,nxt+1))
        {
            s[n][m]=true;
            return true;
        }
    }
    return false;

}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>c;
            if(c=='y')
            {
                wei[++d][0]=i;
                wei[d][1]=j;//记录y的位置方便开始搜索
            }
            a[i][j]=c;
        }
    }
    while(d)
    {
        int u=wei[d][0],v=wei[d][1];
        for(int i=1;i<=8;i++)
        {

            if(a[u+x[i]][v+y[i]]=='i')
            {
                if(solve(u+x[i],v+y[i],x[i],y[i],3))
                {
                    s[u][v]=true;
                    //s[u+x[i]][v+y[i]]=true;
                }
            }

        }
         d--;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(s[i][j])
                cout<<a[i][j];
            else cout<<"*";
        }
        cout<<endl;
    }

    return 0;
}
