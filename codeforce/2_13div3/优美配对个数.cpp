#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int _N = 1e5 + 5;

int T;

//˼·������ܹ��������ֱ�ȡģ��ȣ�����Ҫ��¼ÿ����ȡģ
//���������ȡģ��ȣ��ֱ�ȡģ�����ȡģΪ0

void solve()
{
	int n, x, y; cin >> n >> x >> y;
	vector<int> a(n + 1);

	map<pair<int, int>, int> mp;//���ڷ���ĳ����Ϣ���ɶ��ٸ�����ǰ���pair��Ӧ���������������������ݣ���map����Ӧ
	for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
	ll ans = 0;
	for (int i = 1; i <= n; i++)
    {
		ans += mp[{(x - a[i] % x) % x, a[i] % y}];//�ڶ�����ʾǰ���ȡģ��Ҫ��ȣ���һ����ʾ���ȡģΪ0
        mp[{a[i] % x, a[i] % y}]++;//��¼ȡģ�������֮�󣬱���ÿ����ȥ���
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


