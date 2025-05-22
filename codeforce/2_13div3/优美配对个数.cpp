#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int _N = 1e5 + 5;

int T;

//思路：相减能够整除，分别取模相等，所以要记录每个数取模
//相加两个数取模相等，分别取模相加再取模为0

void solve()
{
	int n, x, y; cin >> n >> x >> y;
	vector<int> a(n + 1);

	map<pair<int, int>, int> mp;//便于访问某个信息点由多少个数，前面的pair对应的是满足两个条件的数据，用map来对应
	for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
	ll ans = 0;
	for (int i = 1; i <= n; i++)
    {
		ans += mp[{(x - a[i] % x) % x, a[i] % y}];//第二个表示前后的取模数要相等，第一个表示相加取模为0
        mp[{a[i] % x, a[i] % y}]++;//记录取模，在相加之后，便于每步都去配对
	}
	cout << ans << '\n';
	return;
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> T;
	while (T--)
    {
		solve();
	}
}


