#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
typedef long long ll;
ll t,n;
//对差值进行前缀和处理
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n;
        vector<ll> arr(n);
        map<ll,ll> mapp;
        ll ans=0;
        bool temp=false;
        mapp[0]++;
        for(int i=0;i<=n-1;i++)
        {
            cin>>arr[i];
            if(i&1){
                ans+=arr[i];
            }
            else
                ans-=arr[i];
            if(mapp[ans])
            {
                temp=true;
            }
            mapp[ans]++;
        }
        if(temp) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;

    }
}

/*#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <iostream>
#include <queue>
#include <cmath>
#include <map>
typedef long long LL;
using namespace std;
inline int read() {
	int num = 0 ,f = 1; char c = getchar();
	while (!isdigit(c)) f = c == '-' ? -1 : f ,c = getchar();
	while (isdigit(c)) num = (num << 1) + (num << 3) + (c ^ 48) ,c = getchar();
	return num * f;
}
const int N = 5e5 + 5;
int n; LL sum[2][N];
inline void mika_solve() {
	n = read();
	map <LL ,bool> mp;
	for (int i = 1; i <= n; i++) {
		sum[0][i] = sum[0][i - 1];
		sum[1][i] = sum[1][i - 1];
		sum[i & 1][i] += read();
	}
	mp[0] = true;
	for (int i = 1; i <= n; i++) {
		if (mp[sum[0][i] - sum[1][i]]) return puts("Yes") ,void();
		mp[sum[0][i] - sum[1][i]] = true;
	}
	puts("No");
}
signed main() {
	int t = read();
	while (t--) mika_solve();
	return 0;
}
*/
