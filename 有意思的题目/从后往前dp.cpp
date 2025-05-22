/* https://atcoder.jp/contests/abc331/tasks/abc331_b */
#include<bits/stdc++.h>
using namespace std;
int n;
int val[3];
int dp[10005];
int main()
{
    ios::sync_with_stdio(0);
	cin.tie(0);

	//freopen("D:\\�㷨����\\At coder\\2023_12.2\\in.txt","r",stdin);
	cin>>n>>val[0]>>val[1]>>val[2];
	memset(dp,0x3f3f3f,sizeof(dp));
	dp[0]=0;
	for(int i=0;i<=n;i++)//����Ϊ�˴���������������Ӻ���ǰdp������
    {
        dp[i+6]=min(dp[i+6],dp[i]+val[0]);
        dp[i+8]=min(dp[i+8],dp[i]+val[1]);
        dp[i+12]=min(dp[i+12],dp[i]+val[2]);

    }

    for(int i=n+12;i>=n-1;i--)
        dp[i]=min(dp[i+1],dp[i]);

    cout<<dp[n]<<endl;


    return 0;

}
