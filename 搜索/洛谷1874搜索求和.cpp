/*思想就是枚举每一个加号的位置，但是这里更多是搜索的技巧*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, ans = INT_MAX, num;
string a;
string b;
bool tp, zero;
void dfs(string s, int x) {
    int sum = 0, k = 0;
    while (isdigit(s[k])) //找到数字
    {
        sum = sum * 10 + s[k] - '0';
        k++;
    }
    for (int i = k; i < s.size(); i++) {
        if (s[i] == '+') {
            i++;
            num = 0;
            while (isdigit(s[i])) //给加号后面的求和
            {
                num = num * 10 + s[i] - '0';
                i++;
            }
            i--;
            sum += num;
        }
    }
    if (sum < n)
        return;
    if(x > ans)
    	return;
    if (sum == n) {
        ans = min(ans, x);
        return;
    }
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i - 1] != '+' && s[i] != '+') {
            string ss;
            for (int j = 0; j < i; j++) ss += s[j];
            ss += '+';
            for (int j = i; j < s.size(); j++) ss += s[j];
            dfs(ss, x + 1);
        }
    }
}
signed main() {
    cin >> a >> n;
    for(int i = 0;i < a.size();i++) {
    	if(a[i] != '0')
    		zero = 1;
    	if(zero)
    		b += a[i];
	}
    dfs(b, 0);
    if (ans > 1e9)
        puts("-1");
    else
        cout << ans;
    return 0;
}
