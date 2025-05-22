#include<iostream>
using namespace std;

struct Edge  //ÿһ��edge����һ���ߣ�������Ŵ�����
{
	int next;  //��һ��ͬ���ıߵ����
	int to;  //������ָ��ĵ�
	int w;  //�����ߵĳ���
};

Edge edge[101];  //�ȶ����101����

int head[101];  //head[i],������iΪ���ıߵ���������head[i]��������������������

int cnt = 1;   //���߱�������¼�ߵ���ţ�˳��(�����˳�㣬������ܷǱ�Ҫ)��¼���м����ߣ�add������һ���Լ�һ��

void add(int u, int v, int w)  //�����u��v�ĳ���Ϊw�ı�
{
    edge[cnt].w = w;  //��cnt���߳�Ϊw
    edge[cnt].to = v;  //��cnt����ָ���v
    edge[cnt].next = head[u];  //��һ����uΪ���������ŵıߵ������head[u]��ÿһ���߶���¼������һ��ͬ���ıߵ���ţ���next
    head[u] = cnt++;  //������uΪ���������ŵıߵ������cnt��
}

int main()
{
    for (int i = 0; i < 101; i++)  //������head��ʼ��Ϊ-1��������iΪ���������С�ıߵ�nextֵΪ-1
        head[i] = -1;

    int m, n;  //m���㣬n����
    cin >> m >> n;

    for (int i = 1; i <= n; i++)  //�ߵ�����
    {
        int u, v,w;
        cin >> u >> v>>w;
        add(u, v, w);
    }

    for (int i = 1; i <= m; i++)  //���ÿ����iΪ����������
    {
        for (int j = head[i]; j != -1; j=edge[j].next)  //����iΪ���������ű߿�ʼ��ͨ��ÿ���ߵ�next���ƴӶ����ΰ��ߵ���ŴӴ�С����ߣ���j=-1��˵���������
        {
            cout <<"��һ������  "<< i << " --->" << edge[j].to << "  ����Ϊ" << edge[j].w << endl;
        }
    }
    return 0;
}
