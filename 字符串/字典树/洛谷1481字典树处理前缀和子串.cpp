#include<bits/stdc++.h>
using namespace std;
int n, dp[2010], ans;
string s[2010];
int main()
{
	scanf ("%d", &n);
	for (int i=1; i<=n; i++)
		cin >>s[i];

	for (int i=1; i<=n; i++)
	{
		dp[i] = 1;
		for (int j=1; j<i; j++)
			if (s[j]==s[i].substr(0,s[j].size())) //从s[i]的0号位置截取s[j]长度的子串，判断是否与s[j]相等。
				dp[i] = max(dp[j]+1, dp[i]);
		ans = max(dp[i], ans);
	}
	printf ("%d", ans);
	return 0;
}
