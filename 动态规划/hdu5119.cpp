//һ���Ǽ�¼ǰ�����ݵĺͣ�һ����״̬ת��
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6 + 10;
const int M = 45;

int dp[M][N];//��ʾ����ǰi����������Ϊj�����
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
		dp[0][0] = 1;//��¼������dp����ʼ��
		for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=1e6;j++)
            {
                dp[i][j]+=dp[i-1][j]+dp[i-1][j^a[i]];//��������е���������ĳ���������������ͬһ�������ǵõ�����
            }
        }
		ll sum = 0;
		for (int i = m; i <= N; i++)
		{
			sum += dp[n][i];//ͳ�Ʊ�m�����
		}
		cout << "Case #" << ++cas << ": " << sum << endl;
	}
	return 0;
}


