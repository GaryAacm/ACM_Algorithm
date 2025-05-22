#include <bits/stdc++.h>

using i64 = long long;

const i64 MAXN =  3e5+10;
const i64 mod = 1e9+7;
const i64 inf = 0x3f3f3f3f3f3f3f3f;
int a[MAXN];

void solve() {
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }
    int mx = 1;
    for (int i = 1; i <= n; i++) {
        if(a[i] < a[mx]) {
            mx = i;
        }
    }
    int Flag = 1;
    for(int i = mx + 1; i <= n; i++) {
        if(a[i] < a[i - 1]) {
            Flag=0;
        }
    }//看排完之后是否非降序
    if(!Flag) {
        std::cout << "-1\n";
        return;
    }
    std::cout << mx - 1 <<"\n";//因为记录到的最后一位满足要求的不用移动
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


