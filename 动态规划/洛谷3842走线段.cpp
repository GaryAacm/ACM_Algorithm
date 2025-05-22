/*处理技巧问题，用绝对值表示距离，以及用二维鸟事上一次状态*/
#include<bits/stdc++.h>
using namespace std;
int n,a[20001][2],dp[20001][2];//a[i][0]表示l[i],a[i][1]表示r[i]
int dis(int a,int b)//计算距离
{
	return abs(a-b);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d",&a[i][0],&a[i][1]);
	dp[1][0]=dis(a[1][1],1)+dis(a[1][1],a[1][0]);
	dp[1][1]=dis(a[1][1],1);
	for(int i=2;i<=n;i++)//状态转移
	{
		dp[i][0]=min(dp[i-1][0]+dis(a[i-1][0],a[i][1])+dis(a[i][1],a[i][0]),dp[i-1][1]+dis(a[i-1][1],a[i][1])+dis(a[i][1],a[i][0]))+1;
		dp[i][1]=min(dp[i-1][0]+dis(a[i-1][0],a[i][0])+dis(a[i][0],a[i][1]),dp[i-1][1]+dis(a[i-1][1],a[i][0])+dis(a[i][0],a[i][1]))+1;
	}
	printf("%d",min(dp[n][0]+dis(a[n][0],n),dp[n][1]+dis(a[n][1],n)));
	return 0;
}
