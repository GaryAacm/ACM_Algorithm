#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6+5;
int n,m;
int dp[MAXN];
int pre[MAXN];
int arr[MAXN];

int main()
{
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        memset(dp,0,sizeof(dp));
        memset(pre,0,sizeof(pre));
        for(int i=1;i<=n;i++)
            scanf("%d",&arr[i]);
        int maxnum;
        for(int i=1;i<=m;i++)//��ʾ������ڵڼ��飬ÿ�ζ���������Ϳ���ʹ��ÿ�ζ��ܵõ�Ҫ��Ҫ������һ���飬�����Զ������˲���Ҫ������
        {
            maxnum=-0x3f3f3f3f;

            for(int j=i;j<=n;j++)
            {
                dp[j]=max(dp[j-1]+arr[j],pre[j-1]+arr[j]);
                pre[j-1]=maxnum;
                maxnum=max(maxnum,dp[j]);
            }
        }
        printf("%d\n",maxnum);
    }
}
//���鿴https://blog.csdn.net/weixin_43835911/article/details/93239103?spm=1001.2101.3001.6650.1&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7ERate-1-93239103-blog-107916097.235%5Ev38%5Epc_relevant_default_base3&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7ERate-1-93239103-blog-107916097.235%5Ev38%5Epc_relevant_default_base3&utm_relevant_index=2
