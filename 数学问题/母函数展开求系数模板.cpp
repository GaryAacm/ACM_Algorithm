#include<bits/stdc++.h>
using namespace std;
const int maxn=205;
int c1[maxn+1],c2[maxn+1];//c1�洢��������c2�洢��ʱ���
int n;
void part()
{
    int i,j,k;
    for(i=0;i<=maxn;i++)
        c1[i]=1,c2[i]=0;//��ʼ��c1����(1+x+x2+...)�����ǵ�һ��1�ü���
    for(k=2;k<=maxn;k++) //�ӵڶ��ʼ���ڶ�����2�ü���
    {
        for(i=0;i<=maxn;i++)
        {
            for(j=0;j+i<=maxn;j+=k)
            {
                c2[i+j]+=c1[i];//������,ģ��չ����õ�ϵ��
            }
        }
        for(i=0;i<=maxn;i++)
            c1[i]=c2[i],c2[i]=0;//��ֵ
    }
}

