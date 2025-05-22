#include<bits/stdc++.h>
using namespace std;
int s;
const int COIN=101;//������100��Ӳ��
const int MONEY=251;
int type[5]={1,5,10,25,50};
int dp[MONEY][COIN];//��ʾ�ճ�money����Ľ����Ŀ

void solve()
{
    dp[0][0]=1;
    for(int k=0;k<5;k++)
    {
        for(int i=1;i<COIN;i++)
        {
            for(int j=type[k];j<MONEY;j++)
                dp[j][i]+=dp[j-type[k]][i-1];
        }
    }
}

int main()
{
    int ans[MONEY]={0};
    solve();
    for(int i=0;i<MONEY;i++)
    {
        for(int j=0;j<COIN;j++)
        {
            ans[i]+=dp[i][j];//ͳ��һ�е�Ӳ����Ŀ
        }
    }
    while(cin>>s)
    {
        cout<<ans[s]<<endl;
    }
    return 0;
}
