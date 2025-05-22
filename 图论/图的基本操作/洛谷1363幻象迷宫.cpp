/*��̼������⣬�࿪һά�洢ԭ���ģ������ȡģ����ͬ�˾����ظ�����*/
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
    vis[x][y][0]=1;//��¼�߹�
    vis[x][y][1]=lx;//��¼ԭ���Ĳ�ȡģ��
    vis[x][y][2]=ly;

    for(int i=0;i<4;i++)
    {
        int lxx = lx + disx[i], lyy = ly + disy[i];
        int xx=(x+disx[i]+n)%n,yy=(y+disy[i]+m)%m;
        if(a[xx][yy]!='#')
        {
            if(!vis[xx][yy]||vis[xx][yy][1]!=lxx || vis[xx][yy][2]!=lyy)
                dfs(xx,yy,lxx,lyy);//һ��Ҫ����һ������ֹ�߲��������߹��ĵ�·
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
