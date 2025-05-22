#include <bits/stdc++.h>
#include <time.h>
#include <random>
using namespace std;
using LL = long long;
#define int long long
#define lowbit(x) ((x)&(-x))
#define PII pair<int,int>
#define endl '\n'
const int N = 1e3 + 10, M = 998244353;
int n, m, vis[N][N], cnt;
char a[N][N];
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };
int qpow(int a, int b) {
	int ans = 1;
	while (b) {
		if (b & 1)ans = ans * a % M;
		a = a * a % M;
		b >>= 1;
	}
	return ans;
}
int inv(int x) {
	return qpow(x, M - 2);
}
void solve() {
	cin >> n >> m;
	int sum = 0;
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= m;j++) {
			cin >> a[i][j];
			sum += a[i][j] == '.';
		}
	}
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= m;j++) {
			if (vis[i][j] || a[i][j] == '.')continue;
			cnt++;
			queue<PII>q; q.push({ i,j });
			while (!q.empty()) {
				int x = q.front().first, y = q.front().second; q.pop();
				if (vis[x][y])continue;
				vis[x][y] = cnt;
				for (int k = 0;k < 4;k++) {
					int xx = x + dx[k], yy = y + dy[k];
					if (a[xx][yy] == '#')q.push({ xx,yy });
				}
			}
		}
	}
	int xu = inv(sum);
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= m;j++) {
			if (a[i][j] == '#')continue;
			set<int>st;
			for (int k = 0;k < 4;k++) {
				int xx = i + dx[k], yy = j + dy[k];
				if (vis[xx][yy])st.insert(vis[xx][yy]);
			}
			if (!st.size())cnt = (cnt + xu) % M;
			else if (st.size() == 1);
			else if (st.size() == 2)cnt = (cnt - xu) % M;
			else if (st.size() == 3)cnt = (cnt - 2 * xu) % M;
			else cnt = (cnt - 3 * xu) % M;
		}
	}
	cnt = (cnt % M + M) % M;
	cout << cnt << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int tt = 1;
	while (tt--) {
		solve();
	}
	//return 0;
}
