#include <bits/stdc++.h>

using namespace std;

const int N = 55;
int n, m, k, a[N], b[N];

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
      cin >> b[i];
    }

    for (int t = 0; t != 4; t++)//4次一个轮回
    {
      if (t == k)
      {
        break;
      }

      sort(a + 1, a + n + 1), sort(b + 1, b + m + 1);
      if (!(t & 1))
     {
        if (a[1] < b[m])
        {
          swap(a[1], b[m]);
        }
      }
      else
      {
        if (b[1] < a[n])
        {
          swap(b[1], a[n]);
        }
      }
    }
    k = max(0, k - 4);

    sort(a + 1, a + n + 1), sort(b + 1, b + m + 1);
    if (k % 2 == 1 && a[1] <= b[1] && b[m] >= a[n]) //奇数
    {
      swap(a[1], b[m]);
    }

    long long s = 0;
    for (int i = 1; i <= n; i++)
    {
      s += a[i];
    }
    cout << s << '\n';
  }
}



