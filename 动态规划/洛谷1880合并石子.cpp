#include<iostream>
#include<cstdio>
using namespace std;
int cnt[210],s[210][210],dp[210][210],n,temp,te,dp2[210][210],maxn,minn;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&cnt[i]),cnt[i]+=cnt[i-1],s[i][i]=i,s[i+n][i+n]=i+n;//ƽ���ı��ζ����Ż�

	for(int i=1;i<=n;i++)cnt[i+n]=cnt[i]+cnt[n];//��״��Ϊ����2n����״

	for(int i=n*2;i>=1;i--)
		for(int j=i+1;j<=n*2;j++)
		{
			//temp=0x7fffffff;
			dp[i][j]=1e9;
			dp2[i][j]=max(dp2[i+1][j],dp2[i][j-1])+cnt[j]-cnt[i-1]; //���ֵ�ͽ����˶˵����Ľ��кϲ�
			for(int k=s[i][j-1];k<=s[i+1][j];k++)
			{
				if(dp[i][j]>dp[i][k]+dp[k+1][j]+cnt[j]-cnt[i-1])
				{
					dp[i][j]=dp[i][k]+dp[k+1][j]+cnt[j]-cnt[i-1];
					s[i][j]=k;
				}
			}
			//dp[i][j]=temp;
			//s[i][j]=te;
		}
	minn=0x7fffffff;
	for(int i=1;i<=n;i++)//�ڵ�һ��������
	{
		minn=min(minn,dp[i][i+n-1]);
		maxn=max(maxn,dp2[i][i+n-1]);
	}
	printf("%d\n%d",minn,maxn);
	return 0;
}
