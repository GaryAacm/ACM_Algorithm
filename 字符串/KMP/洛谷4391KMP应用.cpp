#include<bits/stdc++.h>
using namespace std;
const int maxn=1111111;
int n,kmp[maxn];//kmp���鼴next����
char ss[maxn];
int main()
{
	scanf("%d%s",&n,ss+1);//��1��ʼ����
	int j=0;
	for(int i=2;i<=n;++i)
	{
		while(j&&ss[i]!=ss[j+1]) j=kmp[j];
		if(ss[i]==ss[j+1]) ++j;
		kmp[i]=j;
	}
	printf("%d",n-kmp[n]);//���Ϊ����ѭ������λ��Ӧ
	//����С��ѭ���Ӵ�����Ϊx����ônext[x]=0,next[x+1]=1��һֱѭ����next[n]=n-x
	return 0;
}
