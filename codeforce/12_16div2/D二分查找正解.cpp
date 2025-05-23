    #include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> p(n);
    for (int i = 0; i < n; i++) {
        std::cin >> p[i];
    }

    i64 ans = 0;
    i64 res = n;
    std::vector<int> s{-1};
    for (int i = 0; i < 2 * n; i++) {
        while (s.size() > 1 && p[i % n] < p[s.back() % n]) {
            int x = s.back();
            s.pop_back();
            res -= 1LL * p[x % n] * (x - s.back());
        }
        res += 1LL * p[i % n] * (i - s.back());
        s.push_back(i);
        if (i >= n) {
            ans = std::max(ans, res);
        }
    }

    std::cout << ans << "\n";
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
