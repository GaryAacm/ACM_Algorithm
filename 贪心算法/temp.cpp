
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
int s,t;
int n;

struct num
{
    int begin;
    int end;
    bool operator < (const num & w) const //对左端点由小到大进行排序
    {
        return begin < w.begin ;
    }
}p[N];

int main ()
{
    cin >> s >> t;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int a,b;
        cin >> a >> b;
        p[i] = {a, b};
    }
    sort(p, p + n);

    int res = 0;
    bool k = false;

    for(int i = 0; i <n; i ++) //i 表示区间的个数，依次枚举每个区间
    {
        int j = i, r = -2e9; //r 用来储存能覆盖区间s 的区间的右端点
        while(j < n && p[j].begin <= s)
        {
            r = max (p[j].end , r);
            j ++; // j表示已经枚举过区间的个数
        }

        if(r < s)
        {
            res = -1;
            break;
        }
        res ++;
        if(r >= t)
        {
            k = true;
            break;
        }
        s = r;
        i = j - 1;

    }
    if(!k) res = -1;
    cout << res << endl;

    return 0;
}

