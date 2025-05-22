#include<bits/stdc++.h>
using namespace std;

int la,lb,a[110],b[110],dp[110][110];//状态定义,表示A的i与B的j匹配上的最值

//将状态定义为d，方便处理数值
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
    //输入并转化字符为对应的标号
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

	//处理边界
	dp[0][0]=0;
	for(int i=1;i<=la;i++)
    {
        dp[i][0]=dp[i-1][0]+d[a[i]][5];
    }
	for(int i=1;i<=lb;i++)
    {
        dp[0][i]=dp[0][i-1]+d[5][b[i]];
    }

    //开始dp
    for(int i=1;i<=la;i++)
    {
        for(int j=1;j<=lb;j++)
            //以第i和j是否匹配上为dp端点
        {
            dp[i][j]=max(dp[i-1][j-1]+d[a[i]][b[j]],max(dp[i-1][j]+d[a[i]][5],dp[i][j-1]+d[5][b[j]]));
        }
    }
    cout<<dp[la][lb]<<endl;

    return 0;
}
