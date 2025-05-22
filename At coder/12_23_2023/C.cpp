#include<bits/stdc++.h>
using namespace std;
long long dp[200005][2];
int n, k, a[200005];
int main() {
	cin >> n >> k;
	for (int i = 1; i <= k; i++)cin >> a[i];
	for (int i = 2; i <= k; i++) {
		dp[i][0] = dp[i - 2][0] + a[i] - a[i - 1];
		dp[i][1] = min(dp[i - 1][0], dp[i - 2][1] + a[i] - a[i - 1]);
	}
	cout << dp[k][k % 2];
	return 0;
}
