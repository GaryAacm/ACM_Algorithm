
#include <bits/stdc++.h>

using i64 = long long;

const i64 MAXN =  3e5+7;
const i64 inf = 0x3f3f3f3f3f3f3f3f;

int dp[MAXN], a[MAXN];

void solve() {
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
    	dp[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
    	std::cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
        if(i == 1 || (abs(a[i] % 2) != abs(a[i - 1] % 2))){
            dp[i] = std::max(a[i],dp[i - 1] + a[i]);
        } else dp[i] = a[i];
    }
    int ans = inf *- 1;
    for(int i = 1;i <= n; i++) {
        ans=std::max(ans,dp[i]);
    }
    std::cout<< ans <<"\n";
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	std::cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}
