#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e6+10;

ll a[maxn],b[maxn];
int n,m;
int main()
{
    //freopen("D:\\�㷨����\\ǰ׺�Ͳ��\\in.txt","r",stdin);
    scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		b[i]=a[i]-a[i-1];//��ʼ���,����������
	}
	int l,r,c;
	while(m--)//m��ѯ��
	{
		scanf("%d%d%d",&l,&r,&c);
		b[l]+=c;
		b[r+1]-=c;
	}
	for(int i=1;i<=n;i++)
	{
		b[i]+=b[i-1];

	}
	sort(b+1,b+1+n);
	printf("%lld",b[1]);

	return 0;
}

