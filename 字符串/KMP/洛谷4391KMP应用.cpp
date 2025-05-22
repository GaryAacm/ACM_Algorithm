#include<bits/stdc++.h>
using namespace std;
const int maxn=1111111;
int n,kmp[maxn];//kmp数组即next数组
char ss[maxn];
int main()
{
	scanf("%d%s",&n,ss+1);//从1开始输入
	int j=0;
	for(int i=2;i<=n;++i)
	{
		while(j&&ss[i]!=ss[j+1]) j=kmp[j];
		if(ss[i]==ss[j+1]) ++j;
		kmp[i]=j;
	}
	printf("%d",n-kmp[n]);//理解为出现循环的首位对应
	//设最小的循环子串长度为x，那么next[x]=0,next[x+1]=1，一直循环到next[n]=n-x
	return 0;
}
