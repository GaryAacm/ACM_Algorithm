/*˼·����������Ϊ2�Ķ��ٴη�������ö�ٶ����Ƶ�λ������¼������λ���ĳ��ִ���
����ö��λ���Ƿ����*/
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
        while (l < r)//������ö����Ҫ��ǰλ���Ķ��ٸ���
        {
            int mid = (l+r+1) >> 1;
            if ((mid << i) <= v) l = mid;
            else r = mid-1;
        }
        v -= r << i;//ÿ��ö�ٵ���һ�����䣬�ͼ���v
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
