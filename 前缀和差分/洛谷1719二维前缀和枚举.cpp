#include<bits/stdc++.h>
using namespace std;
#define MAXN 150
int a[MAXN][MAXN],n,m,q;
int main()
{
	//freopen("D:\\�㷨����\\ǰ׺�Ͳ��\\in.txt","r",stdin);
	scanf("%d%",&n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}//��������

	 for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
		}
	}//���ÿ������Ӧ�ľ������ݵĺ�
	int ans=-1e9;
	for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int l=1;l<=n;l++)
            {
                for(int r=1;r<=n;r++)
                {
                    if(l<i||r<j) continue;//�����������
                    ans=max(ans,a[l][r]-a[i-1][r]-a[l][j-1]+a[i-1][j-1]);
                }
            }
        }
    }

    cout<<ans<<endl;

	return 0;
}
