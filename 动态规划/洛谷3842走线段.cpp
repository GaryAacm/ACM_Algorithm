/*���������⣬�þ���ֵ��ʾ���룬�Լ��ö�ά������һ��״̬*/
#include<bits/stdc++.h>
using namespace std;
int n,a[20001][2],dp[20001][2];//a[i][0]��ʾl[i],a[i][1]��ʾr[i]
int dis(int a,int b)//�������
{
	return abs(a-b);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d",&a[i][0],&a[i][1]);
	dp[1][0]=dis(a[1][1],1)+dis(a[1][1],a[1][0]);
	dp[1][1]=dis(a[1][1],1);
	for(int i=2;i<=n;i++)//״̬ת��
	{
		dp[i][0]=min(dp[i-1][0]+dis(a[i-1][0],a[i][1])+dis(a[i][1],a[i][0]),dp[i-1][1]+dis(a[i-1][1],a[i][1])+dis(a[i][1],a[i][0]))+1;
		dp[i][1]=min(dp[i-1][0]+dis(a[i-1][0],a[i][0])+dis(a[i][0],a[i][1]),dp[i-1][1]+dis(a[i-1][1],a[i][0])+dis(a[i][0],a[i][1]))+1;
	}
	printf("%d",min(dp[n][0]+dis(a[n][0],n),dp[n][1]+dis(a[n][1],n)));
	return 0;
}
