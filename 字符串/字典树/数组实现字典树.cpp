#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int tree[maxn][26];
int num[maxn]={0};//��ĳһ�ַ���Ϊǰ׺�ĵ�������
int pos=1;
//�·���Ĵ洢λ��

void Insert(char str[])//�ֵ����в���
{
    int p=0;
    for(int i=0;str[i];i++)
    {
        int n=str[i]-'a';//��ʾ�����ĸ��ͷ�ĵ���
        if(tree[p][n]==0)//��û��ֵ��Ӧ�����ĸ
        {
            tree[p][n]=pos++;//ָ��ͬ�洢λ�ã������µĴ洢λ��

        }
        p=tree[p][n];//ָ����һ���洢λ�ã�����ǰ׺

        num[p]++;//�Դ˽�β������˵�Դ�Ϊǰ׺
    }
}

int Find(char str[])//�����Դ�Ϊǰ׺�ĵ�������
{
    int p=0;//����
    for(int i=0;str[i];i++)//һ��һ������
    {
        int n=str[i]-'a';
        if(tree[p][n]==0)//���ֲ����ʵ�
            return 0;
        p=tree[p][n];
    }

    return num[p];
}
