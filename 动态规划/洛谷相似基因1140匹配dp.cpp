#include<bits/stdc++.h>
using namespace std;

int la,lb,a[110],b[110],dp[110][110];//״̬����,��ʾA��i��B��jƥ���ϵ���ֵ

//��״̬����Ϊd�����㴦����ֵ
int d[6][6]=
{
	{0,0,0,0,0,0},
	{0,5,-1,-2,-1,-3},
	{0,-1,5,-3,-2,-4},
	{0,-2,-3,5,-2,-2},
	{0,-1,-2,-2,5,-1},
	{0,-3,-4,-2,-1,0}
};

int main()
{
    cin>>la;
    //���벢ת���ַ�Ϊ��Ӧ�ı��
	for(int i=1;i<=la;i++)
	{
		char t;
		cin>>t;
		switch(t)
		{
		case'A':
			a[i]=1;break;
		case'C':
			a[i]=2;break;
		case'G':
			a[i]=3;break;
		case'T':
			a[i]=4;break;
		}
	}
	cin>>lb;
	for(int i=1;i<=lb;i++)
	{
		char t;
		cin>>t;
		switch(t)
		{
		case'A':
			b[i]=1;break;
		case'C':
			b[i]=2;break;
		case'G':
			b[i]=3;break;
		case'T':
			b[i]=4;break;
		}
	}

	//����߽�
	dp[0][0]=0;
	for(int i=1;i<=la;i++)
    {
        dp[i][0]=dp[i-1][0]+d[a[i]][5];
    }
	for(int i=1;i<=lb;i++)
    {
        dp[0][i]=dp[0][i-1]+d[5][b[i]];
    }

    //��ʼdp
    for(int i=1;i<=la;i++)
    {
        for(int j=1;j<=lb;j++)
            //�Ե�i��j�Ƿ�ƥ����Ϊdp�˵�
        {
            dp[i][j]=max(dp[i-1][j-1]+d[a[i]][b[j]],max(dp[i-1][j]+d[a[i]][5],dp[i][j-1]+d[5][b[j]]));
        }
    }
    cout<<dp[la][lb]<<endl;

    return 0;
}
