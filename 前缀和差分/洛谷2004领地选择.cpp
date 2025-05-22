#include<bits/stdc++.h>
using namespace std;
#define long long int
const int maxn=1005;
int n,m,c;
int a[maxn][maxn];
int ans1,ans2;
signed main()
{
    cin>>n>>m>>c;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            cin>>a[i][j];
    }
    for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
		}
	}
	int maxx=-1e9;
	for(int i=1;i+c-1<=n;i++)
    {
        for(int j=1;j+c-1<=m;j++)
        {
            int k=a[i+c-1][j+c-1]-a[i-1][j+c-1]-a[i+c-1][j-1]+a[i-1][j-1];
            if(maxx<k)
            {
                maxx=k;
                ans1=i;
                ans2=j;
            }
        }
    }
    cout<<ans1<<' '<<ans2;
}
