#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
//�ýṹ���Ż�
struct edge
{
    int from,to,wei;
    edge(int a,int b,int c)//��ʼ��,����ͬʱ����Ȩֵ���յ����⣬����Ҫ�ٿ�����һ��vector����
    {
        from=a;
        to=b;
        wei=c;
    }
};

vector<edge> e[maxn];

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<=n;i++)
        e[i].clear();//���
    for(int i=1;i<=n;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        e[i].push_back(edge(a,b,c));
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<e[i].size();j++)
        {
            cout<<e[i][j].from<<endl;//�����չʾ�������
        }
    }

    return 0;
}
