#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=10005;

//ͨ�õ�dfsģ�壬����ݹ鵽��ײ㴦�����ӽڵ�Ȼ�����ڵ�
/*void dfs(int v) { // �����ڵ�v
	dp[v] = ...; // ��ʼ��
	for(int u: G[v]) { // ����v�������ӽڵ�
		dfs(u);
		update(u, v); // ���ӽڵ��dpֵ�Ե�ǰ�ڵ��dpֵ���и���
	}
}
*/

//��������С

/*#include <cstdio>
#include <vector>
#define maxn 100
using namespace std;

vector<int> G[maxn]; // �ڽӱ�
int sz[maxn]; // dp���飬sz[v] = ����v�Ĵ�С

void dfs(int v)
{
	sz[v] = 1; // ��ʼ���������СΪ1�������ۼ�
	for(int i=0;i<G[v].size();i++) // �����ӽ��
	{
        int u=G[v][i];
		dfs(u); // �ȶ��ӽ�����dfs
		sz[v] += sz[u]; // ���µ�ǰ�����Ĵ�С
	}
}

int main()
{
	int n;
	scanf("%d", &n); // ������
	for(int i=1; i<n; i++) // N-1����
	{
		int u, v;
		scanf("%d%d", &u, &v); // ����һ����
		G[u].push_back(v); // �����ڽӱ�
	}
	dfs(1);
	for(int i=1; i<=n; i++)
		printf("%d\n", sz[i]);
	return 0;
}
*/

//����û����˾�����
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

signed main()
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
