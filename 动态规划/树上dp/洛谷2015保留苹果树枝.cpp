#include<bits/stdc++.h>
using namespace std;
const int maxn=110;
vector<int> tree[maxn];
int n,q;
int a,b,temp;
int value[maxn][maxn],vis[maxn];
int dp[maxn][maxn];//��ʾ���˵�i���ڵ��ʱ����������j����֦
void dfs(int father)
{
    vis[father]=1;//��ֹ�ظ�����
    for(int i=0;i<tree[father].size();i++)
    {
        int son=tree[father][i];

        if(vis[son]==1) continue;//�ظ��ң�˵���Ǹ��ڵ�
        dfs(son);//����dp���ģ��ݹ鴦��

        for(int j=q;j>=1;j--)//ö����������
        {
            for(int k=0;k<j;k++)//ö�ٵ�ʱ����һ�������ڵ�
                {
                    dp[father][j]=max(dp[father][j],value[father][son]+dp[son][k]+dp[father][j-k-1]);//���ϵ�ǰ��������son�����ģ�ʣ�µ��Ǹ��ױ�����
                }
        }
    }

}

int main()
{
    cin>>n>>q;
    for(int i=1;i<n;i++)
    {
        cin>>a>>b>>temp;
        tree[a].push_back(b);
        tree[b].push_back(a);
        value[a][b]=value[b][a]=temp;
        //˫���ߣ������֪�����ĸ��Ǹ��׽ڵ������
    }

    dfs(1);
    cout<<dp[1][q]<<endl;

    return 0;
}

