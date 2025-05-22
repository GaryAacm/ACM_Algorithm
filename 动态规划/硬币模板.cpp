#include<bits/stdc++.h>
using namespace std;

const int MONEY=251;
const int VALUE=5;//��ֵ���������
int MIN[MONEY];//��¼��С�Ľ����
int MIN_Path[MONEY];//��¼��С�����
int type[5]={1,5,10,15,25};
int s;
void solve()//�������
{

    for(int i=0;i<MONEY;i++)
        MIN[i]=INT_MAX;//��ʼ��Ϊ���
    MIN[0]=0;
    for(int i=0;i<VALUE;i++)
    {
        for(int j=type[i];j<MONEY;j++)
        {
            if(MIN[j]>MIN[j-type[i]]+1)
            {
                MIN_Path[j]=type[i];//��¼·�����õ�Ӳ��
                MIN[j]=MIN[j-type[i]]+1;
            }
        }
    }
}

void print_ans(int *MIN,int s)
{
    while(s)
    {
        cout<<MIN_Path[s]<<' ';
        s-=MIN_Path[s];//�ݼ�����s
    }
    cout<<endl;
}

int main()
{
    solve();//�����
    while(cin>>s)
    {
        cout<<MIN[s]<<endl;
        print_ans(MIN_Path,s);
    }
    return 0;
}
