/*for(int i = 1; i <= n; i++)
{
    for(int j = 1; j <= C; j++) //CΪ�����������
    {
        //k�Ĵ����൱�ڿ�������Ʒ�ĸ���num[i]
        for(int k = 1; k <= num[i]; k++)
        {
            if(W[i] * k > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - W[i] * k] + V[i] * k);
            }
        }
    }
}*/

//�������Ż�
//���Ǻϲ���ֵ���������

#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+10;
int n,V;
int v[MAXN],w[MAXN];
int f[MAXN];
int main()
{
	cin>>n>>V;
	int cnt=0;//��¼�µ�������
	for(int i=1,a,b,s;i<=n;i++)
	{
		cin>>a>>b>>s;
		int k=1;
		while(k<=s)//ʵ��1  2  4  8��ԭ��Ʒ  �ϳ�Ϊ����Ʒ
		{
			v[++cnt]=k*a;
			w[cnt]=k*b;
			s-=k;
			k*=2;
		}
		if(s)
		{
			v[++cnt]=s*a;
			w[cnt]=s*b;
		}
	}

	for(int i=1;i<=cnt;i++)//01����
		for(int j=V;j>=v[i];j--)
			f[j]=max(f[j],f[j-v[i]]+w[i]);
	cout<<f[V];
	return 0;
}



