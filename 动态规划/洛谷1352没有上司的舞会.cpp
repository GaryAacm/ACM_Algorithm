#include<bits/stdc++.h>
using namespace std;
const int maxn=6005;

int n,father[maxn],value[maxn];
vector<int> tree[maxn];
int a,b;
int dp[maxn][2];

void dfs(int t)
{
    dp[t][0]=0;//��ѡ
    dp[t][1]=value[t];//ѡ
    for(int i=0;i<tree[t].size();i++)//�����ӽڵ�
    {
        int son=tree[t][i];//��¼�ӽڵ�
        dfs(son);//�����ӽڵ�
        dp[t][0]+=max(dp[son][0],dp[son][1]);
        dp[t][1]+=dp[son][0];
    }
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        {
            scanf("%d",&value[i]);
            father[i]=-1;//��ʼ��Ϊ�˺������׽ڵ�
        }
        for(int i=1;i<n;i++)
        {
            scanf("%d%d",&a,&b);

            tree[b].push_back(a);//��������¼���ڵ����ӵ��ӽڵ�
            father[a]=b;
        }
        int t=1;
        while(father[t]!=-1)
        {
            t=father[t];//�ݹ��ҵ����ڵ�
        }
        dfs(t);//����������
        printf("%d\n",max(dp[t][1],dp[t][0]));
    return 0;
}

