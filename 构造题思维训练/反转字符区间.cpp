#include<bits/stdc++.h>
using namespace std;
int T,n,m;
char ch[100005],s1[50005],s2[50005];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%s",&n,&m,ch+1);
		if(m%2==0){sort(ch+1,ch+n+1),printf("%s\n",ch+1);continue;}//偶数可以任意改变位置
		for(int i=1;i<=n;++i)//奇数不能改变奇偶位置，交替输出
		{
			if(i%2) s1[(i+1)/2]=ch[i];
			else s2[i/2]=ch[i];
		}
		sort(s1+1,s1+(n+1)/2+1),sort(s2+1,s2+n/2+1);
		for(int i=1;i<=n/2;++i) printf("%c%c",s1[i],s2[i]);
		if(n%2) printf("%c",s1[(n+1)/2]);
		puts("");
	}
	return 0;
}
