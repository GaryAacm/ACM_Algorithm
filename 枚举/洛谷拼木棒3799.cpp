# include <cstdio>
# include <iostream>
# include <algorithm>
using namespace std;
const int N=100005;
const int mod=1e9+7;
int n,a[N],f[N],sum;
int s=1e9,e=-1e9;//分别是最小最大长度
long long ans;

int main ()
{
	scanf ("%d",&n);
	for (int i=1;i<=n;i++)
    {
		scanf ("%d",&a[i]);
		s=min(s,a[i]);
		e=max(e,a[i]);
		f[a[i]]++;//记录该长度出现次数
	}
	for (int i=s+1;i<=e;i++)
    {
		if (f[i]<=1) continue;//不可能组成三角，否则找到两根长度一样的

		for (int j=s;j<=i/2;j++)//枚举两根长度组成i的
			if (f[j]&&f[i-j])//能组成三角
				if (j!=i-j)
					ans=ans+((f[i]*(f[i]-1)>>1)*f[j]*f[i-j])%mod;//次数不相等，从f[i]里面选两根
				else if (f[j]>=2)
					ans=ans+((f[i]*(f[i]-1)>>1)*(f[j]*(f[j]-1)>>1)%mod)%mod;//直接f[j]中取2
	}
	printf ("%lld\n",ans%mod);//输出即结束
	return 0;
}
