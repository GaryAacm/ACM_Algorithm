//一个是记录前面数据的和，一个是状态转移
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6 + 10;
const int M = 45;

int dp[M][N];//表示的是前i个数的异或和为j的情况
int cas;
int a[M];

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		scanf ("%d%d", &n, &m);
		memset(dp, 0,sizeof(dp));
		for (int i = 1; i <= n; i++)
		{
			scanf ("%d", &a[i]);
		}
		dp[0][0] = 1;//记录数量的dp，初始化
		for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=1e6;j++)
            {
                dp[i][j]+=dp[i-1][j]+dp[i-1][j^a[i]];//计算出所有的异或情况，某个数连续两次异或同一个数就是得到本身
            }
        }
		ll sum = 0;
		for (int i = m; i <= N; i++)
		{
			sum += dp[n][i];//统计比m大的数
		}
		cout << "Case #" << ++cas << ": " << sum << endl;
	}
	return 0;
}


