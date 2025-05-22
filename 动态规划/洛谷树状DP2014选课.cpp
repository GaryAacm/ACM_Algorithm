#include<bits/stdc++.h>
using namespace std;

const int maxn=305;

int value[maxn];
vector<int> tree[maxn];
int n,m;
int dp[maxn][maxn];//iΪ���ڵ㣬ѡ��j�ڿ�

void dfs(int father)
{
    dp[father][1]=value[father];
    dp[father][0]=0;
    for(int i=0;i<tree[father].size();i++)
    {
        int son=tree[father][i];
        dfs(son);//ÿ�εݹ�����ӽڵ��ֵ

        for(int j=m+1;j>=1;j--)//ö�����
        {
            for(int k=0;k<j;k++)//ö��������Ʒ
            {
                dp[father][j]=max(dp[father][j],dp[son][k]+dp[father][j-k]);//����ѡ���׵��Ǽ������Բ���kȡ��j
            }
        }
    }
}

int main()
{
    cin>>n>>m;
    value[0]=0;
    memset(dp,0xcf,sizeof(dp));//��ʼ��������

    for(int i=1;i<=n;i++)
    {
       int s,k;
        cin>>k>>s;
        value[i]=s;//��¼��Ӧ��ѧ��
       tree[k].push_back(i);
    }
    dfs(0);//��0��ͳһ���е�����,��Ϊ���ڵ�
    cout<<dp[0][m+1]<<endl;
    return 0;
}
