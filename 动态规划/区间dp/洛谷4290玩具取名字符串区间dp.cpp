/*����dp�����е����������һ�飬˼·��������dpö�����䣬�ұ�ȫ���ܹ�ת�������*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=205;
int dp[maxn][maxn][5],able[5][5][5];//��ʾ1�ſ�����2��3ת������
int q[5];
char c[2],s[maxn];
int change(char x)
{
    if(x=='W') return 1;
    else if(x=='I') return 2;
    else if(x=='N') return 3;
    else return 4;
}

int main()
{
    for(int i=1;i<=4;i++)
    {
        cin>>q[i];
    }
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=q[i];j++)
        {
            cin>>c[0]>>c[1];
            able[i][change(c[0])][change(c[1])]=1;//��ʾ����ת��
        }
    }
    cin>>s+1;
    int len=strlen(s+1);
    for(int i=1;i<=len;i++) dp[i][i][change(s[i])]=true;//��i��i���������Լ�ת��
    //��ʼ����dp
    for(int mid=1;mid<=len;mid++)
    {
        for(int l=1;l+mid<=len;l++)
        {
            int r=l+mid;//�Ҷ˵�
            for(int k=l;k<r;k++)//�ϵ�
            {
                //�ؼ�
                for(int a1=1;a1<=4;a1++)//�о�l��r����ת���ɵ���ĸ
                    {
                        for(int a2=1;a2<=4;a2++)//�о�l��k
                        {
                            for(int a3=1;a3<=4;a3++)//�о�k + 1��r
                            {
                                if(able[a1][a2][a3]&&dp[l][k][a2]&&dp[k+1][r][a3])//l��k������a2ת����
                                    dp[l][r][a1]=1;
                            }
                        }
                    }
            }
        }
    }
    bool flag=false;
    if(dp[1][len][1]) {flag=true;cout<<'W';}
    if(dp[1][len][2]) {flag=true;cout<<'I';}
    if(dp[1][len][3]) {flag=true;cout<<'N';}
    if(dp[1][len][4]) {flag=true;cout<<'G';}
    if(!flag) cout<<"The name is wrong!";

    return 0;
}
