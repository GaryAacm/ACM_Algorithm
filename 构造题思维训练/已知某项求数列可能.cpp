#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef __int128 i128;
typedef long double ld;
const int N=2000005;
int n,x;

int getint()
{
	char ch;
	int f=1;
	while(!isdigit(ch=getchar())) if(ch=='-') f=-1;
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x*f;
}

LL getLL()
{
	char ch;
	int f=1;
	while(!isdigit(ch=getchar())) if(ch=='-') f=-1;
	LL x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x*f;
}

int calc(int n,int k)
{
	int rt=0;
	for(int i=1; i*i<=n; ++i)
    if(n%i==0)//вђзг
	{
		if(i>=k && i%2==0) ++rt;
		if(i*i<n && n/i%2==0 && n/i>=k) ++rt;
	}
	return rt;
}

void solve()
{
	n=getint(),x=getint();
	int ans=0;
	ans+=calc(n-x,x*2-2);
	if(x>1) ans+=calc(n+x-2,x*2-1);
	printf("%d\n",ans);
}

int main()
{
	int T=getint();
	while(T--) solve();
	return 0;
}



