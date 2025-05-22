//从子集开始dp，直到完成全部dp
/*  https://atcoder.jp/contests/abc332/tasks/abc332_e  */
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,d,x;
	long double w[15];
	long double ave=0;
	long double dp[(1<<15)][16];//当前二进制情况下包括进来的数的分组的最小值
	long double y;

	cin>>n>>d;

	for(int i=0;i<n;i++)cin>>w[i],ave+=w[i];
	ave/=((long double)d);//求平均值

	for(int i=0;i<(1<<n);i++)
    {
		y=0;
		for(int j=0;j<n;j++)
        {
			if(i&(1<<j))
                y+=w[j];//枚举要不要加入这位数，二进制枚举所有情况
		}
		dp[i][1]=pow(y-ave,2);//第一组,子集里面的元素加入
		for(int j=2;j<=d;j++)//枚举分组情况
		{
			dp[i][j]=dp[i][j-1]+dp[0][1];//初始化，前面一组加上没有子集,第一个数分一组
			x=i;
			while(x>0)
            {
				dp[i][j]=min(dp[i][j],dp[i-x][j-1]+dp[x][1]);//把x的子集拿出来分到单独的一组
				x=(x-1)&i;
			}
		}
	}
	cout<< setprecision(10) <<(dp[(1<<n)-1][d]/((long double)d))<<endl;//保留10位有效数字
	return 0;
}
