#include <bits/stdc++.h>
using namespace std;
long long t,n,k,x;
int main() {
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%lld",&n,&k,&x);
		if(k*(1+k)/2>x)		//情况 1
		{
			printf("NO\n");
		}
		else if(k*(n-k+1+n)/2<x)	//情况 2
		{
			printf("NO\n");
		}
		else
		{
			printf("YES\n");
		}
	}

	return 0;
}
