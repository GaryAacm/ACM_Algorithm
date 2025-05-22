#include<bits/stdc++.h>
using namespace std;
#define MAXN 10010
int a[MAXN],n,m,b[MAXN];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		b[i]=a[i]-a[i-1];//开始差分,构造差分数组
	}

	int l,r,c;
	while(m--)//m次询问
	{
		scanf("%d%d%d",&l,&r,&c);
		b[l]+=c;
		b[r+1]-=c;
	}
	for(int i=1;i<=n;i++)
	{
		b[i]+=b[i-1];
		printf("%d ",b[i]);//求前缀和
	}
	return 0;
}
