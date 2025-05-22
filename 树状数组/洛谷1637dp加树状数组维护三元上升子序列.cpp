#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
ll n,a[maxn],num[maxn],dp[4][maxn],ans,c[maxn];//dp表示以a[j]结尾的长度为i上升子序列个数
//转移方程是：f[i][j]=f[i-1][k](k<j&&a[k]<a[j])

ll lowbit(ll k)
{
    return k&(-k);
}


ll sum(ll x)
{
    ll tot=0;
    while(x)
    {
        tot+=c[x];
        x-=lowbit(x);
    }
    return tot;
}

void update(ll p,ll k)
{
    while(p<=n)
    {
        c[p]+=k;
        p+=lowbit(p);
    }
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        num[i]=a[i];
    }
    sort(num+1,num+1+n);
    int m=unique(num+1,num+1+n)-num-1;
    for(int i=1;i<=n;i++)
    {
        a[i]=lower_bound(num+1,num+1+m,a[i])-num;
        dp[1][i]=1;//初始化
    }
    for(int i = 2; i <= 3; i++)//利用树状数组维护前缀和，这里维护的是2到3的转化
    {
		memset(c, 0, sizeof(c));//清空树状数组的节点值
		for(int j = 1; j <= n; j++)
		{
			dp[i][j] = sum(a[j]-1);//查询前缀
			update(a[j], dp[i-1][j]);
		}
	}

    for(int i=1;i<=n;i++) ans+=dp[3][i];
    cout<<ans<<endl;
}

