#include<bits/stdc++.h>
using namespace std;
int t,n,a[200005],b[200005];//b数组可以省略
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",a+i),b[i]=a[i];
		int ans=a[1];
		for(int i=2;i<=n;)
        {
            if(abs(a[i])%2!=abs(a[i-1])%2)
            {
                b[i]=max(a[i]+b[i-1],a[i]);

            }
            ans=max(ans,b[i++]);
        }

		printf("%d\n",ans);
	}
	return 0;
}
