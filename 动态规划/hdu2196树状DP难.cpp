#include<bits/stdc++.h>
using namespace std;
const int maxn=10010;
struct node
{
    int id;
    int cost;
};
vector<node> tree[maxn];
int dp[maxn][3];//0��ʾ�ӽڵ㵽����������룬1��ʾ�������룬2��ʾ�������Ҹ��ڵ��������
int n;

void dfs1(int u)//��0��1
{
    int one=0,two=0;
    for(int i=0;i<tree[u].size();i++)
    {
        node son=tree[u][i];
        dfs1(son.id);//�������ϵݹ�
        int cost= son.cost+dp[son.id][0];
        if(cost>=one)
        {
            two=one;
            one=cost;//��¼���͵ڶ������
        }
        if(cost>two&&one>cost)
            two=cost;//���µڶ�С
    }
    dp[u][0]=one;
    dp[u][1]=two;
}

void dfs2(int u)//��2
{
    for(int i=0;i<tree[u].size();i++)
    {
        node son=tree[u][i];
        if(dp[son.id][0]+son.cost==dp[u][0])//�����������,�Ѵ���������ߵ�
        {
            dp[son.id][2]=max(dp[u][2],dp[u][1])+son.cost;
        }
        else
            dp[son.id][2]=max(dp[u][2],dp[u][0])+son.cost;//������������ϣ�����������ߵģ�ע����µ����ӽڵ�
        dfs2(son.id);//��Ϊ���ӽڵ��𲽸��µģ������������
    }
}

int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++)
            tree[i].clear();
        memset(dp,0,sizeof(dp));
        for(int i=2;i<=n;i++)
        {
            node temp;
            int x,y;
            scanf("%d%d",&x,&y);
            temp.id=i;
            temp.cost=y;
            tree[x].push_back(temp);
        }
        dfs1(1);
        dp[1][2]=0;
        dfs2(1);
        for(int i=1;i<=n;i++)
            printf("%d\n",max(dp[i][0],dp[i][2]));//�ӽڵ����������

    }
    return 0;
}
