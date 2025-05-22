#include<bits/stdc++.h>
using namespace std;

int r,c,ans;
int a[105][105];
int s[105][105];//��¼��ǰ·�����ڼ��仯
int walkx[4]={1,-1,0,0};
int walky[4]={0,0,1,-1};
int dfs(int x,int y)
{
    if(s[x][y]) return s[x][y];//�Ѿ��������ˣ����仯����
    s[x][y]=1;//Ĭ���ѹ���
    for(int i=0;i<4;i++)
    {
        int xx=x+walkx[i];
        int yy=y+walky[i];
        if(xx>0&&yy>0&&xx<=r&&yy<=c&&a[x][y]>a[xx][yy])//����Ҫ���������
        {
            dfs(xx,yy);
            s[x][y]=max(s[x][y],s[xx][yy]+1);
        }
    }
    return s[x][y];
}

int main()
{
    cin>>r>>c;
    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=c;j++)
            cin>>a[i][j];
    }
    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=c;j++)
            ans=max(ans,dfs(i,j));
    }
    cout<<ans<<endl;
    return 0;
}
