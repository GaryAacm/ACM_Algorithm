
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 300010
using namespace std;
ll n,a[N];
bool check(ll v)
{
	ll i,l=0,r=n-1;
	for(i=0;i<n;i++)
	{
		if(v<a[i])
		{
			return false;
		}
		if(v-i<a[i])
		{
			l=max(l,i);
		}
		if(v-(n-i-1)<a[i])
		{
			r=min(r,i);
		}
	}
	if(l>r)
	{
		return false;
	}
	return true;
}
int main(){
	ll i;
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
	}
	ll l=0,r=INF+INF;
	while(l<r)
	{
		ll mid=(l+r)>>1;
		if(check(mid))
		{
			r=mid;
		}
		else
		{
			l=mid+1;
		}
	}
	printf("%lld\n",l);
	return 0;
}
