#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9+10;

int grap[101][101];
int n,m,a,b;

int main()
{
    cin.tie(0);
    cout.tie(0);
    memset(grap,-1,sizeof(grap));
    //cout<<grap[1][2];
    cin>>n>>m;
    for(int i=1;i<=m;++i)
    {
        cin>>a>>b;
        grap[b][a]=1;
    }

    for(int k=1;k<=n;k++)//枚举分割点
    {
        for(int i=1;i<=n;i++)
        {
            if(grap[i][k]!=-1)//优化
            {
                for(int j=1;j<=n;j++)
                {
                    grap[i][j]=(grap[i][k]&&grap[k][j])||grap[i][j];//判断是否可达,初始化-1这里判断出问题

                }

            }
        }
    }

    int a=1;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        a=1;
        for(int j=1;j<=n;j++)
        {
            if(i==j) continue;
            else
            {
                //a=(grap[i][j]||grap[j][i])&&a;//i跟其他全部点都建立了联系
                if(grap[i][j]==0&&grap[j][i]==0)
                    a=0;
            }
        }
        ans+=a;
    }
    cout<<ans;

    return 0;
}
