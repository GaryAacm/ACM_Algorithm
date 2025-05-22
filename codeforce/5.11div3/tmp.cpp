#include<bits/stdc++.h> 

 
#define fir first
#define sec second
#define mpr make_pair
 
#define vv vector
#define eb emplace_back
 
#define Fr(i,l,r) for(ll i = l; i <= r; ++i)
#define Rf(i,r,l) for(ll i = r; i >= l; --i)
using namespace std;
using ll = long long;

template<typename T> void in(T& x) {
	x = 0; char ch = getchar(); bool f = false;
	while (!isdigit(ch)) f = f || ch == '-', ch = getchar();
	while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	if (f) x = -x;
}
 
void solve() {
	ll x; in(x);
	int ans = -1, val = 0;
	Fr (y, 1, x - 1) {
		if (__gcd(x, y) + y > val) val = __gcd(x, y) + y, ans = y;
	}
	printf("%d\n", ans);
}
 
int main() {
	int T; in(T);
	while (T --> 0) solve();
	return 0;
}
