/*注意思路就是含有1的是特殊情况，然后就是利用好count和find函数
然后枚举从a【1】开始实行转化，用ans的pair数组记录，然后观察发现有2出现都可以转化为2*/
#include<bits/stdc++.h>

using namespace std;
using PII = pair<int, int>;

const int N = 110;

int n;
int a[N];
PII ans[N * 35];
int cnt;

void solve() {
	cnt = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];

	if (count(a + 1, a + n + 1, a[1]) == n) {
		cout << 0 << '\n';
		return;
	}

	if (count(a + 1, a + n + 1, 1) >= 1) {
		cout << -1 << '\n';
		return;
	}

	while (count(a + 1, a + n + 1, a[1]) < n && count(a + 1, a + n + 1, 2) == 0) {
		int pos = 2;
		while (a[pos] == a[1]) {
			pos++;
		}

		if (a[pos] > a[1]) {
			if (a[pos] % a[1]) a[pos] = a[pos] / a[1] + 1;
			else a[pos] = a[pos] / a[1];
			ans[++cnt] = {pos, 1};
		}
		else {
			if (a[1] % a[pos]) a[1] = a[1] / a[pos] + 1;
			else a[1] = a[1] / a[pos];
			ans[++cnt] = {1, pos};
		}
	}

	if (count(a + 1, a + n + 1, a[1]) < n) {
		int pos2 = find(a + 1, a + n + 1, 2) - a;
		for (int i = 1; i <= n; i++) {
			while (a[i] != 2) {
				if (a[i] & 1) a[i] = a[i] / 2 + 1;
				else a[i] = a[i] / 2;
				ans[++cnt] = {i, pos2};
			}
		}
	}

	cout << cnt << '\n';
	for (int i = 1; i <= cnt; i++) cout << ans[i].first << ' ' << ans[i].second << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) solve();
	return 0;
}
