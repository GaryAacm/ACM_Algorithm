#include<bits/stdc++.h>
using namespace std;
const int maxn=510;
int a[maxn],b[maxn],c[maxn];

void add()//�߾��ȼӷ�
{
    string A,B;
    cin>>A>>B;
    int len=max(A.length(),B.length());
    for(int i=A.length()-1,j=1;i>=0;i--,j++)
    {
        a[j]=A[i]-'0';
    }
    for(int i=B.length()-1,j=1;i>=0;i--,j++)
    {
        b[j]=B[i]-'0';
    }
    for(int i=1;i<=len;i++)//��ĩλ��ʼģ���λ
    {
        c[i]+=a[i]+b[i];
        c[i+1]=c[i]/10;
        c[i]=c[i]%10;

    }
    if(c[len+1]) len++;
    for(int i=len;i>=1;i--)
        cout<<c[i];
    return ;
}

void mul()
{
    string A,B;
    cin>>A>>B;
    for(int i=A.length()-1,j=1;i>=0;i--,j++)
    {
        a[j]=A[i]-'0';
    }
    for(int i=B.length()-1,j=1;i>=0;i--,j++)
    {
        b[j]=B[i]-'0';
    }
    int lena=A.length();
    int lenb=B.length();

    for(int i=1;i<=lena;i++)
    {
        for(int j=1;j<=lenb;j++)
            c[i+j-1]+=a[i]*b[j];
    }//�����ĳһλ���ֵĹ���

    int len=lena+lenb;
    for(int i=1;i<=len;i++)//�����λ�Ĺ���
    {
        c[i+1]+=c[i]/10;
        c[i]=c[i]%10;
    }
    for(;!c[len];) len--;//ȥ����λ��0
    for(int i=max(1,len);i>=1;i--)
    {
        cout<<c[i];
    }
    return;
}

int main()
{
    add();
    mul();
    return 0;
}

