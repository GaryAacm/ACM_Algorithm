#include<bits/stdc++.h>
using namespace std;
const int md=1000000007;

int n,m,k;
char a[1001],b[201];
int dp[2][201][201][2];//�ֱ��ʾʹ����Aƥ���˶���B�����˼����Ӵ�����û����ǰ���

int main()
{
    scanf("%d%d%d",&n,&m,&k);
    scanf("%s%s",a+1,b+1);
    dp[0][0][0][0]=1;//��ʼ��
    dp[1][0][0][0]=1;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            for(int p=1;p<=k;p++)
            {
                if(a[i]==b[j])
                {
                    dp[i%2][j][p][0]=dp[(i-1)%2][j][p][0]%md+dp[(i-1)%2][j][p][1]%md;
                    dp[i%2][j][p][0]%=md;
                    dp[i%2][j][p][1]=(dp[(i-1)%2][j-1][p-1][0]%md+dp[(i-1)%2][j-1][p][1]%md)%md+dp[(i-1)%2][j-1][p-1][1]%md;//ÿһ����ȡģ������������ȡģ��
                    dp[i%2][j][p][1]%=md;
                }
                else//ƥ�䲻�ϣ�����
                {
                    dp[i%2][j][p][0]=dp[(i-1)%2][j][p][0]+dp[(i-1)%2][j][p][1];
                    dp[i%2][j][p][0]%=md;
                    dp[i%2][j][p][1]=0;//������
                }
            }
        }
    }
    printf("%d",(dp[n%2][m][k][1]+dp[n%2][m][k][0])%md);

    return 0;
}
