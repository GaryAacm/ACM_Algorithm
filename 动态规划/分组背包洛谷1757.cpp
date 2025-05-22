#include<bits/stdc++.h>
using namespace std;

int n,t,a,b,c,m;
int group[1005],num[1005][1005];//num表示对应组数的编号
int w[1005],val[1005];
int dp[1005];
int main()
{
    cin>>m>>n;
    int all=0;
    for(int i=1;i<=n;i++)
    {
        cin>>w[i]>>val[i]>>c;
        all=max(all,c);//求最大组数
        group[c]++;//小组元素加一
        num[c][group[c]]=i;
    }

    for(int i=1;i<=all;i++)//枚举组数
    {
        for(int j=m;j>=0;j--)//先枚举容量，因为后面不同组不同处理
        {
            for(int k=1;k<=group[i];k++)//枚举小组的元素，k是第几个元素
            {
                if(j>=w[num[i][k]])
                   dp[j]=max(dp[j],dp[j-w[num[i][k]]]+val[num[i][k]]);
            }
        }
    }

    cout<<dp[m]<<endl;

    return 0;
}
