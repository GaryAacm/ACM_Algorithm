#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
typedef long long ll;

struct Edge  //ÿһ��edge����һ���ߣ�������Ŵ�����
{
	int next;  //��һ��ͬ���ıߵ����
	int to;  //������ָ��ĵ�
	int w;  //�����ߵĳ���
};

Edge edge[maxn*2],edgereverse[maxn*2];  //���������,����������ǵã�����

int head[101];  //head[i],������iΪ���ıߵ���������head[i]��������������������

int cnt = 1;   //���߱�������¼�ߵ���ţ�˳��(�����˳�㣬������ܷǱ�Ҫ)��¼���м����ߣ�add������һ���Լ�һ��

void add(int u, int v, int w)  //�����u��v�ĳ���Ϊw�ı�
{
    edge[cnt].w = w;  //��cnt���߳�Ϊw
    edge[cnt].to = v;  //��cnt����ָ���v
    edge[cnt].next = head[u];  //��һ����uΪ���������ŵıߵ������head[u]��ÿһ���߶���¼������һ��ͬ���ıߵ���ţ���next
    head[u] = cnt++;  //������uΪ���������ŵıߵ������cnt��
}

/*int headre[maxn];

int cntre = 1;

void addreverse(int u, int v, int w)
{
    edgereverse[cntre].w = w;
    edgereverse[cntre].to = v;
    edgereverse[cntre].next = headre[u];
    headre[u] = cntre++;
}
*/
//---------- ������ ------------
ll Size[maxn];//��ʾ�����Դ�Ϊ���ڵ��������С
ll ans=0;
int n,a,b,c;
void dfs(int u,int fa)
{
    Size[u]=1;
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==fa) continue;
        dfs(v,u);
        Size[u]+=Size[v];
        ans+=edge[i].w*abs(2*Size[v]-n);//����ѱ�Ȩ�����ӽڵ㣡����
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    //freopen("D:\\�㷨����\\��\\in.txt","r",stdin);
    cin>>n;
    for(int i=1;i<=n-1;i++)
    {
        cin>>a>>b>>c;
        add(a,b,c);
        add(b,a,c);
    }

    ans=0;
    dfs(1,0);
    cout<<ans<<endl;

    return 0;
}
