#include<bits/stdc++.h>
using namespace std;
const int maxn=10010;
struct node
{
    int x,y,tim;
}a[maxn];
int dp[maxn],n,m;//dp��ʾ����iֻС���ʱ��ץ���˼�ֻ

int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
        cin>>a[i].tim>>a[i].x>>a[i].y;
    for(int i=1;i<=m;i++)
        dp[i]=1;//��ʼ��Ϊ1
    int maxnn=-1;
    //�����ʼ��Ϊ0������ö�ٰ����Լ�Ҳ���У���Ϊ���ܲ������Լ�
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<i;j++)//ö��ǰ�������,����ö���Լ���������ظ�
        {
            if(abs(a[i].x-a[j].x)+abs(a[i].y-a[j].y)<=abs(a[i].tim-a[j].tim))
            {
                //���Դﵽ
                dp[i]=max(dp[i],dp[j]+1);

            }

        }
        maxnn=max(maxnn,dp[i]);
    }
    cout<<maxnn<<endl;
    return 0;
}

