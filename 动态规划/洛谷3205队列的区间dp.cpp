#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
int dp[maxn][maxn][2],a[maxn];
int n;
//�����ϻ��Ƿָ����ΪС����Ĳ���
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        dp[i][i][0]=1;//��ʼ����Ĭ�ϴ���߽�ȥΪ1,ֻ�ǳ�ʼ��һ�߾��У���Ϊ���Ҫ0��1���

    }

    //���Ʒ������ڵ������������ԭ����ʲô����Ƴ���

    for(int len=2;len<=n;len++)
    {
        for(int i=1;i+len-1<=n;i++)
        {
            int j=i+len-1;
            //����߽�ȥ
            if(a[i]<a[i+1]) dp[i][j][0]+=dp[i+1][j][0];
            if(a[i]<a[j]) dp[i][j][0]+=dp[i+1][j][1];
            //���ұ߽�ȥ
            if(a[j]>a[j-1]) dp[i][j][1]+=dp[i][j-1][1];
            if(a[j]>a[i]) dp[i][j][1]+=dp[i][j-1][0];

            dp[i][j][0]%=19650827;
			dp[i][j][1]%=19650827;
        }
    }
    cout<<(dp[1][n][0]+dp[1][n][1])%19650827<<endl;

    return 0;
}
