#include <bits/stdc++.h>
using namespace std;

int n, m, ans = 1e9;
int a[15][15], b[15][15];
int c[15], d[15], vis1[15], vis2[15];

void dfs1(int p) {
	if (p == m + 1) {
		bool f = true;
		for (int i = 1; i <= n; i++) {
			if (!f) break;
			for (int j = 1; j <= m; j++) {
				if (a[c[i]][d[j]] != b[i][j]) {
					f = false;
					break;
				}
			}
		}
		if (f) {
			int cnt = 0;
			for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++)
			if (c[i] > c[j]) cnt++;

			for (int i = 1; i <= m; i++)
			for (int j = i + 1; j <= m; j++)
			if (d[i] > d[j]) cnt++;
			ans = min(ans, cnt);
		}
		dfs1(1);
		return ;
	}
	for (int i = 1; i <= m; i++) {
		if (!vis2[i]) {
			vis2[i] = 1;
			d[p] = i;
 			dfs1(p + 1);
			vis2[i] = 0;
		}
	}
}

void dfs2(int p)
{
	if (p == n + 1) {
		dfs1(1);
		return ;
	}
	for (int i = 1; i <= n; i++) {
		if (!vis1[i]) {
			vis1[i] = 1;
			c[p] = i;
 			dfs2(p + 1);
			vis1[i] = 0;
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++)
	cin >> a[i][j];

	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++)
	cin >> b[i][j];

	dfs2(1);
	if (ans == 1e9) ans = -1;
	cout << ans;
	return 0;
}

