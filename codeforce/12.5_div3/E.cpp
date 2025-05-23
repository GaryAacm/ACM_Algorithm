#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    i64 ans = 1;
    int n;
    std::cin >> n;

    while (n > 0) {
        int x = n % 10;
        ans *= (x + 1) * (x + 2) / 2;
        n /= 10;
    }
    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
