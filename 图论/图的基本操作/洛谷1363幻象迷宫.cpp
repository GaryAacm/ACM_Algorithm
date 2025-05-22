/*编程技巧问题，多开一维存储原来的，如果和取模不相同了就是重复走了*/
#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn=1550;

int n,m;
int st,ed;
char a[maxn][maxn];
int disx[]={1,0,-1,0};
int disy[]={0,1,0,-1};
int vis[maxn][maxn][3];
int cnt;
void dfs(int x,int y,int lx,int ly)
{
   if(cnt) return ;
   if(vis[x][y][0])
   {
       cnt=1;
       return ;
   }
    vis[x][y][0]=1;//记录走过
    vis[x][y][1]=lx;//记录原来的不取模的
    vis[x][y][2]=ly;

    for(int i=0;i<4;i++)
    {
        int lxx = lx + disx[i], lyy = ly + disy[i];
        int xx=(x+disx[i]+n)%n,yy=(y+disy[i]+m)%m;
        if(a[xx][yy]!='#')
        {
            if(!vis[xx][yy]||vis[xx][yy][1]!=lxx || vis[xx][yy][2]!=lyy)
                dfs(xx,yy,lxx,lyy);//一定要有这一步，防止走不到后面走过的的路
        }
    }

}

int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n>>m)
    {
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
                if(a[i][j]=='S')
                {
                    st=i;
                    ed=j;
                }
            }
        }
        cnt=0;
        dfs(st,ed,st,ed);
        if(cnt) cout<<"Yes"<<'\n';
        else cout<<"No"<<'\n';

    }
}
