/*#include<bits/stdc++.h>
using namespace std;
const int maxn=105;

int f,v;
int a[maxn][maxn];
int dp[maxn][maxn];//��i�����j��

void solve(int i,int j)
{
    if(j==0) return ;
    for(int k=0;k<=i-j;k++)
    {
        if(dp[i][j]==dp[j+k-1][j-1]+a[j][j+k])
        {
            solve(j+k-1,j-1);
            cout<<j+k<<' ';
            break;
        }
    }
}

int main()
{
    cin>>f>>v;
     for(int i=1;i<=f;i++)
    {
        for(int j=1;j<=v;j++)
            cin>>a[i][j];
    }
    for(int i=1;i<=f;i++)
        dp[i][i]=dp[i-1][i-1]+a[i][i];
    for(int i=1;i<=v;i++)//����
    {
        for(int j=1;j<=f;j++)//����
        {
            dp[i][j]=-1*0x3f3f3f3f;
            for(int k=0;k<=i-j;k++)//ö�ٺ����ÿ�仨
            {
                dp[i][j]=max(dp[i][j],dp[j+k-1][j-1]+a[j][j+k]);//����һ����ö�ٺ���Ļ�����һ��װ��
            }
        }
    }
    cout<<dp[v][f]<<endl;
    solve(v,f);

    return 0;
}*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
int f[maxn][maxn];
int n,m;
int cost[maxn][maxn];
struct node
{
	int a[maxn];
	int tail;
}way[maxn][maxn];//��¼·��
int main()
{
	memset(f,-127,sizeof(f));
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	   for(int j=1;j<=m;j++)
	      cin>>cost[i][j];
	for(int i=0;i<=m;i++)
	   f[0][i]=0;
	for(int i=1;i<=n;i++)
	   for(int j=i;j<=m;j++)
	   {
	   	   if(f[i-1][j-1]+cost[i][j]>f[i][j-1])
	   	   {
	   	   	  way[i][j]=way[i-1][j-1];//�ṹ�帳ֵ
	   	   	  way[i][j].a[++way[i][j].tail]=j;
	   	   	  f[i][j]=f[i-1][j-1]+cost[i][j];
	   	   }
	   	   else
	   	   {
	   	   	  way[i][j]=way[i][j-1];
	   	   	  f[i][j]=f[i][j-1];
	   	   }
	   }
	cout<<f[n][m]<<endl;
	for(int i=1;i<=way[n][m].tail;i++)
	{
		cout<<way[n][m].a[i]<<" ";//�൱�ڼ�¼�ض���·��
	}
	return 0;
}
