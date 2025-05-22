#include<bits/stdc++.h>
using namespace std;
long long a,l,r;
int m;
int main()
{
	scanf("%lld%d%lld%lld",&a,&m,&l,&r);
	if(a < l || a > r)
	{
		if(a < l) a += (l - a + m - 1) / m * m;
		else a -= (a - r + m - 1) / m * m;
	}
	if(a < l || a > r) puts("0");
	else printf("%lld",(a - l) / m + (r - a) / m + 1);
	return 0;
}
