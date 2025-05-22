#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1024;
int dp[maxn][maxn];
int n,q;
char p[maxn][maxn];
ll query(int x,int y)
{
    ll res=1LL*dp[n][n]*(x/n)*(y/n);//求整个的有几块
    res+=1LL*dp[x%n][n]*(y/n);//加上不完整的块数
    res+=1LL*dp[n][y%n]*(x/n);
    res+=dp[x%n][y%n];
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("D:\\算法进阶\\At coder\\2023_12.2\\in.txt","r",stdin);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>p[i][j];
            dp[i][j]=((p[i][j]=='B')?1:0 ) + dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
        }
    }
    while(q--)
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        c++;
        d++;
        a++;
        b++;
        cout<<query(c,d)-query(c,b-1)-query(a-1,d)+query(a-1,b-1)<<endl;
    }

    return 0;
}

