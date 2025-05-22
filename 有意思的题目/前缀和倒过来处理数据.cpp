/*
https://atcoder.jp/contests/abc331/tasks/abc331_c
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e6+10;
ll n,a[200005],sum[2000005];//注意数据范围

int main()
{
    ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>n;

	for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
        sum[a[i]]+=a[i];
    }
    for(ll i=2000005;i>=0;--i)//倒过来求和就不会加上比它小的数
    {
        sum[i]+=sum[i+1];
    }
    for(ll i=1;i<=n;i++)
        cout<<sum[a[i]+1]<<' ';//加一为了输出比它大的数的和

    return 0;

}

/*
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
int a[200005], cnt[2000005];
signed main(){
	cin >> n;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
		cnt[a[i]] += a[i];
	}
	for(int i = 2000000 ; i >= 0 ; i--){
		cnt[i] += cnt[i + 1];
	}
	for(int i = 1 ; i <= n ; i++) cout << cnt[a[i] + 1] << " ";
	return 0;
}
*/
