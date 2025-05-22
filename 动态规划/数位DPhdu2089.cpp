#include<bits/stdc++.h>
using namespace std;

const int LEN=12;
int dp[LEN+1][10];//i��ʾ�м�λ����j��ʾ��ͷ������
int digit[LEN+1];//�����洢����λ�õ�����

void init()
{
    dp[0][0]=1;
    for(int i=1;i<=LEN;i++)//��λ����
    {
        for(int j=0;j<10;j++)//��ͷ������
        {
            for(int k=0;k<10;k++)//i-1λ�Ŀ�ͷ����
            {
                if(j!=4&&!(j==6&&k==2))//�ų�4��ͷ��62��ͷ��
                    dp[i][j]+=dp[i-1][k];
            }
        }
    }
}

int solve(int x)
{
    int len=0;
    while(x)
    {
        digit[++len]=x%10;
        x/=10;
    }
    int ans=0;int pre=-1;//��¼ǰ���λ��
    for(int i=len;i>=1;i--)//�Ӹ�λ��ʼ
    {
        for(int j=0;j<digit[i];j++)//ö�ٶ�Ӧλ�õ����֣���С����
            {
                if(j!=4&&!(pre=6&&j==2))
                    ans+=dp[i][j];

            }
            if(digit[i]==4||(pre=6&&digit[i]==2))
            {
                ans--;
                break;
            }
            pre=digit[i];

    }
    return ans;
}

int main()
{
    int n,l;
    init();
    while(scanf("%d%d",&l,&n))
    {
        if(l==0&&n==0) break;
        printf("%d\n",solve(n)-solve(l-1));
    }


    return 0;
}
