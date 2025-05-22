#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
const int INF = 1e6;
int n,m,a,b,c,ans=2e9+10;
int grap[maxn][maxn],Grap[maxn][maxn];
int flag=0;

void floyd()
{
    for(int k=1;k<=n;k++)//ö�ٷָ��
    {
        for(int i=1;i<=n;i++)
        {
            if(grap[i][k]!=-1)//�Ż�
            {
                for(int j=1;j<=n;j++)
                {
                    if(grap[k][j]!=-1)
                    {
                        if(grap[i][j]==-1||grap[i][j]>grap[i][k]+grap[k][j])//����min����
                        grap[i][j]=grap[i][k]+grap[k][j];
                    }
                }

            }//һ�����ҵ����е����·

        }

    }
}

void Turnback()//��ԭԭ����
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            Grap[i][j]=grap[i][j];
        }
    }
}

void solve()
{
    ans=2e9;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;j++)
        {
            Turnback();
            Grap[i][j]=Grap[j][i]=0;

            for(int x=1;x<=n;x++)
            {
                for(int y=1;y<=n;y++)
                {
                    if(Grap[x][y]==-1||Grap[x][i]+Grap[i][y]<Grap[x][y])
                        Grap[x][y]=Grap[x][i]+Grap[i][y];
                }
            }
            for(int x=1;x<=n;x++)
            {
                for(int y=1;y<=n;y++)
                {
                    if(Grap[x][y]==-1||Grap[x][j]+Grap[j][y]<Grap[x][y])
                        Grap[x][y]=Grap[x][j]+Grap[j][y];
                }
            }
            int res=0;
            for(int x=1;x<=n;x++)
            {
                for(int y=1;y<x;y++)//ֻ�ܼӵ�x����ֹ�ظ���
                    res+=Grap[x][y];
            }
            ans=min(ans,res);
            //cout<<ans<<endl;
        }
    }
}

int main()
{
    cin>>n>>m;
    memset(grap,-1,sizeof(grap));
    for(int i=1;i<=m;i++)
    {
        cin>>a>>b>>c;
        if(grap[a][b]==-1||grap[a][b]>c) grap[a][b]=grap[b][a]=c;

    }
    floyd();
    solve();
    cout<<ans<<endl;

    return 0;
}
