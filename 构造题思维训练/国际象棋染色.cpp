#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn=105;

int t,n,m;
char c;
int a[maxn][maxn];
//简化问题，不限次数,两个两个地去染色
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        int tot=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>c;
                a[i][j]=c-'0';
                tot+=a[i][j];//计算染色次数
            }
        }
        if(a[1][1])
        {
            cout<<-1<<endl;
            continue;
        }
        cout<<tot<<'\n';
        for(int j=1;j<=m;j++)//从最后一行第一列开始，往上扫盲
        {
            for(int i=n;i>1;i--)
            {
                if(a[i][j])//黑色
                {
                    cout<<i-1<<' '<<j<<' '<<i<<' '<<j<<'\n';
                }
            }
        }
        for(int j=m;j>1;--j)//处理第一行
        {
        	if(a[1][j])
        	{
        		cout<<"1 "<<j-1<<" 1 "<<j<<"\n";
        	}
        }
        memset(a,0,sizeof(a));
    }
}
