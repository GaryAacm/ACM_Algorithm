//���Ӽ���ʼdp��ֱ�����ȫ��dp
/*  https://atcoder.jp/contests/abc332/tasks/abc332_e  */
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,d,x;
	long double w[15];
	long double ave=0;
	long double dp[(1<<15)][16];//��ǰ����������°������������ķ������Сֵ
	long double y;

	cin>>n>>d;

	for(int i=0;i<n;i++)cin>>w[i],ave+=w[i];
	ave/=((long double)d);//��ƽ��ֵ

	for(int i=0;i<(1<<n);i++)
    {
		y=0;
		for(int j=0;j<n;j++)
        {
			if(i&(1<<j))
                y+=w[j];//ö��Ҫ��Ҫ������λ����������ö���������
		}
		dp[i][1]=pow(y-ave,2);//��һ��,�Ӽ������Ԫ�ؼ���
		for(int j=2;j<=d;j++)//ö�ٷ������
		{
			dp[i][j]=dp[i][j-1]+dp[0][1];//��ʼ����ǰ��һ�����û���Ӽ�,��һ������һ��
			x=i;
			while(x>0)
            {
				dp[i][j]=min(dp[i][j],dp[i-x][j-1]+dp[x][1]);//��x���Ӽ��ó����ֵ�������һ��
				x=(x-1)&i;
			}
		}
	}
	cout<< setprecision(10) <<(dp[(1<<n)-1][d]/((long double)d))<<endl;//����10λ��Ч����
	return 0;
}
