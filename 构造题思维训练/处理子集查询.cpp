/*思路处理，就是因为2的多少次方，所以枚举二进制的位数，记录二进制位数的出现次数
二分枚举位数是否符合*/
#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 100010;
int n, x[N];

bool query(int v)
{
    for (int i = 29; i >= 0; i--)
    {
        int l = 0, r = x[i];
        while (l < r)//这里是枚举需要当前位数的多少个数
        {
            int mid = (l+r+1) >> 1;
            if ((mid << i) <= v) l = mid;
            else r = mid-1;
        }
        v -= r << i;//每次枚举到了一个区间，就减少v
    }
    return !v;
}

signed main() {
    cin >> n;
    for (int i = 1, t, v; i <= n; i++) {
        cin >> t >> v;
        if (t == 1) x[v]++;
        else cout << (query(v) ? "YES" : "NO") << '\n';
    }
    return 0;
}
